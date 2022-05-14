#pragma once
#include "better_tokenizer.h"
#include "builtins.h"
#include "proc.h"
#include "string.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool is_redir_tok(const char *s) {

  if (!strcmp(s, "<") | !strcmp(s, ">") | !strcmp(s, ">>")) {
    return true;
  }

  return false;
}

const char invalid_file_name_characters[] = {'#', '%', '&', '{', '}', '\\', '<',
                                             '>', '*', '?', '$', '!', '\'', '"',
                                             ':', '@', '+', '`', '|', '='};

bool chr_in_str(char *s, char c) { return strchr(s, c) != NULL; }

bool has_invalid_char(char *s) {

  for (int i = 0; i < sizeof(invalid_file_name_characters) / sizeof(char);
       i++) {
    if (chr_in_str(s, invalid_file_name_characters[i]))
      return true;
  }

  return false;
}

int redirection_type(char *token) {

  if (!strcmp(token, "<"))
    return 0;
  else if (!strcmp(token, ">"))
    return 1;
  else if (!strcmp(token, ">>"))
    return 2;
  else
    return -1;
}
bool redir_file_valid(char **array) {
  for (char **p = array; *p != NULL; ++p) {
    if (is_redir_tok(*p) && has_invalid_char(*(p + 1))) {
      return false;
    }
  }
  return true;
}

void do_pipeline(char *input) {
  Args *args = tokenize(input);

  char **tokens = args->args;

  int targc = 0;

  for (char **p = tokens; *p != NULL; ++p) {
    targc++;
  }

  if (!strcmp("<", tokens[0]) | !strcmp(">", tokens[0]) |
      !strcmp(">>", tokens[0]) | !strcmp("|", tokens[0])) {
    printf("syntax error near unexpected token `%s'\n", tokens[0]);
  } else if (!strcmp("<", tokens[targc - 1]) | !strcmp(">", tokens[targc - 1]) |
             !strcmp(">>", tokens[targc - 1]) |
             !strcmp("|", tokens[targc - 1])) {
    printf("syntax error near unexpected token `%s'\n", tokens[targc - 1]);
  } else if (redir_file_valid(tokens)) { // we got here: no syntax errors, nice

    int exit_builtin_code = execute_builtin(tokens);
    if (exit_builtin_code == -2) {
      free(input);
      free(args);
      exit(EXIT_SUCCESS);
    } else if (exit_builtin_code == -1) { // builtin not found

      char *file_out = NULL;
      char *file_in = NULL;

      bool append = true;

      for (char **s = tokens; *s != NULL; ++s) {
        switch (redirection_type(*s)) {
        case 0:
          file_in = strdup(*(s + 1));
          for (char **new_args = s; *new_args != NULL; ++new_args) {
            *new_args = *(new_args + 2);
          }
          s -= 2;
          break;
        case 2:
          append = true;
        case 1:
          file_out = strdup(*(s + 1));
          for (char **new_args = s; *new_args != NULL; ++new_args) {
            *new_args = *(new_args + 2);
          }
          s -= 2;
          break;
        }
      }

      char ***pipeline = tokenize_pipeline(tokens);

      execute_pipeline_ex(pipeline, false, file_in, file_out, append);

      free(file_out);
      free(file_in);
      free_pipeline_tokens(pipeline);
    }

  } else {
    printf("syntax error: invalid file name\n"); // oopsies
  }
  free_args(args);
}

void process_input(char *input) {
  char *last_pipe = strtok(input, ";");
  while (last_pipe != NULL) {
    do_pipeline(last_pipe);
    last_pipe = strtok(NULL, ";");
  }
}