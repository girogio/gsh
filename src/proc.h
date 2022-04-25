#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>


#define READ_END 0
#define WRITE_END 1

pid_t fork_exec(char **args);
pid_t fork_exec_pipe(char **cmd1,  char **cmd2, int fd[2]);
pid_t fork_exec_pipe_ex(char **cmd1,  char **cmd2, int fd[2], char *file_in, char *file_out, bool append_out);
int execute_pipeline(char **pipeline_args[], bool async);
int execute_pipeline_ex(char ***pipeline_args, bool async,char *file_in, char *file_out, bool append_out);
