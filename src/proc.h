#pragma once
#include "parser.h"
#include <linux/limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

pid_t fork_exec(char **args) {

  pid_t child = fork();

  if (!child) {
    if (execvp(args[0], args)) {
      perror(args[0]);
      exit(EXIT_FAILURE);
    } else
      perror("Exec failed");
  }
  wait(NULL);
  return child;
}

pid_t fork_exec_pipe(char **args1, char **args2, int fd[2]) {

  if (pipe(fd) == -1) {
    perror("Pipe creation failed."); // bob the builder didn't wake up
    return EXIT_FAILURE;
  }

  pid_t pg1 = fork();
  pid_t pg2;

  if (pg1 == -1) { // child had to be aborted
    perror("Fork failed.");
    return EXIT_FAILURE;
  } else if (!pg1) { // i am the child

    close(fd[READ_END]); // no need to read anything; pg1 is outputting
    dup2(fd[WRITE_END], STDOUT_FILENO); // link stdout to the input of the pipe
    close(fd[WRITE_END]);               // close input of pipe
    execvp(args1[0], args1);            // we can exec now!

  } else {

    pg2 = fork();

    if (pg2 == -1) { // child had to be aborted
      perror("Fork failed.");
      return EXIT_FAILURE;
    } else if (!pg2) { // i am child

      close(
          fd[WRITE_END]); // no need to write to this pipe now; already done so
      dup2(fd[READ_END], STDIN_FILENO); // link stdin to the output of the pipe
      close(fd[READ_END]);              // close the output of the pipe

      execvp(args2[0], args2); // we can exec the program now!

    } else
      wait(NULL); // wait if parent
  }

  return pg2;
}

pid_t fork_exec_pipe_ex(char **cmd1, char **cmd2, int fd[2], char *file_in,
                        char *file_out, bool append_out) {

  if (pipe(fd) == -1) {
    perror("Pipe creation failed."); // bob the builder didn't wake up
    return EXIT_FAILURE;
  }

  pid_t pg1 = fork();
  pid_t pg2;

  if (pg1 == -1) { // child had to be aborted
    perror("Fork failed.");
    return EXIT_FAILURE;
  } else if (!pg1) { // i am the child

    close(fd[READ_END]); // no need to read anything; pg1 is outputting
    dup2(fd[WRITE_END], STDOUT_FILENO); // link stdout to the input of the pipe
    close(fd[WRITE_END]); // `close input of pipe; we're using stdout

    execvp(cmd1[0], cmd1); // we can exec now!

  } else {

    pg2 = fork();

    if (pg2 == -1) { // child had to be aborted

      perror("Fork failed.");
      return EXIT_FAILURE;

    } else if (!pg2) { // i am child

      close(
          fd[WRITE_END]); // no need to write to this pipe now; already done so

      if (file_out != NULL) // output file specified?
        freopen(file_out, append_out ? "a" : "w",
                stdout); // stdout --> file_out

      dup2(fd[READ_END], STDIN_FILENO); // stdin => pipe

      if (file_in != NULL)
        freopen(file_in, "r", stdin); // file_in => stdin

      close(fd[READ_END]); // close the output of the pipe

      execvp(cmd2[0], cmd2); // we can exec the cmd2 now!
    } else {
      wait(NULL); // wait if parent
    }
  }

  return pg2;
}

int execute_pipeline(char ***pipeline_args, bool async) {

  int child_count = 0;

  char ***arg = pipeline_args;

  while (*arg != NULL) {
    child_count++;
    arg++;
  }

  int pipe_count = child_count - 1;

  int fd[pipe_count * 2], *current_fd = fd, *prev_fd = NULL;

  for (int stage = 0; stage < child_count; stage++) {

    prev_fd = current_fd - 2;

    if (stage < child_count - 1)
      pipe(current_fd);

    pid_t child = fork();

    if (child == -1) {
      perror("Fork failed!");
      exit(EXIT_FAILURE);
    } else if (child == 0) {
      if (stage < child_count - 1) {
        close(current_fd[0]);
        dup2(current_fd[1], STDOUT_FILENO);
        close(current_fd[1]);
      }

      if (stage > 0) {
        close(prev_fd[1]);
        dup2(prev_fd[0], STDIN_FILENO);
        close(prev_fd[0]);
      }

      if (execvp(pipeline_args[stage][0], pipeline_args[stage]) == -1) {
        perror(pipeline_args[stage][0]);
        free_pipeline_tokens(pipeline_args);
        exit(EXIT_FAILURE);
      }

      return EXIT_SUCCESS;
    }

    if (stage >= 1) {
      close(prev_fd[0]);
      close(prev_fd[1]);
    }

    current_fd += 2;

    if (!async) {
      waitpid(child, NULL, 0);
    }
  }

  return EXIT_SUCCESS;
}

int execute_pipeline_ex(char ***pipeline_args, bool async, char *file_in,
                        char *file_out, bool append_out) {
  int child_count = 0;

  char ***arg = pipeline_args;
  while (*arg != NULL) {
    child_count++;
    arg++;
  }

  int pipe_count = child_count - 1;

  int fd[pipe_count * 2], *current_fd = fd, *prev_fd = NULL;

  for (int stage = 0; stage < child_count; stage++) {

    prev_fd = current_fd - 2;

    if (stage < child_count - 1)
      pipe(current_fd);

    pid_t child = fork();

    if (child == -1) {
      perror("Fork failed!");
      exit(EXIT_FAILURE);
    } else if (child == 0) {

      if (stage < child_count - 1) { // is it not the end?
        close(current_fd[READ_END]);
        dup2(current_fd[WRITE_END], STDOUT_FILENO);
        close(current_fd[WRITE_END]);
      }

      if (stage == pipe_count && file_out != NULL) // we in last stage?
        freopen(file_out, append_out ? "a" : "w", stdout);

      if (stage == 0 && file_in != NULL)
        freopen(file_in, "r", stdin);
        
      else if (stage > 0) { // is it not the beginning?
        close(prev_fd[WRITE_END]);
        dup2(prev_fd[READ_END], STDIN_FILENO);
        close(prev_fd[READ_END]);
      }

      if (execvp(pipeline_args[stage][0], pipeline_args[stage]) == -1) {
        perror(pipeline_args[stage][0]);
        exit(EXIT_FAILURE);
      }

      return EXIT_SUCCESS;
    }

    if (stage >= 1) {
      close(prev_fd[0]);
      close(prev_fd[1]);
    }

    current_fd += 2;

    if (async == false) {
      waitpid(child, NULL, 0);
    }
  }
  return EXIT_SUCCESS;
}
