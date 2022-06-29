#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "strings.h"
#include <stdio.h>

typedef struct String {
  char *string;
  size_t size;
} String;

typedef struct Args {
  char **args;
  size_t size;
} Args;

String *initialize_string() {
  String *s;
  s = (String *)malloc(sizeof(String));
  s->string = (char *)malloc(sizeof(char));
  s->size = 1;
  s->string[0] = '\0';
  return s;
}

Args *initialize_args() {
  Args *a;
  a = (Args *)malloc(sizeof(Args));
  a->args = (char **)malloc(sizeof(char *));
  a->args[0] = NULL;
  a->size = 1;
  return a;
}

void append_to_args(Args *a, String *s) {
  if (s->size > 1) {
    a->args = (char **)realloc(a->args, sizeof(char *) * (a->size + 1));
    a->args[a->size - 1] = strdup(s->string);
    a->args[a->size++] = NULL;
    s->size = 1;
  }
}

void append_to_string(String *s, char c) {
  s->string = (char *)realloc(s->string, sizeof(char) * (s->size + 1));
  s->string[s->size - 1] = c;
  s->string[s->size] = '\0';
  s->size++;
}

size_t length(String *s) { return s->size - 1; }

void print_string(String *s) {
  for (int i = 0; i < s->size; i++) {
    putchar(s->string[i]);
  }
}

void print_args(Args *a) {
  for (int i = 0; i < a->size - 1; i++) {
    printf("%s\n", a->args[i]);
  }
}

void free_string(String *s) {
  free(s->string);
  free(s);
}

void free_args(Args *a) {
  for (int i = 0; i < a->size; i++)
    free(a->args[i]);
  free(a->args);
  free(a);
}

Args *tokenize(char *line) {

  String *s = initialize_string();
  Args *a = initialize_args();

  for (char *c = line; *c != '\0'; c++) {
    switch (*c) {
    case ' ': // push to the args!
      append_to_args(a, s);
      break;
    case '\\':                                  // escape the escapable
      if (*(c + 1) == '\"' || *(c + 1) == '\\') // escape the unescapable
        append_to_string(s, *++c);
      break;
    case '\"':                              // time to enter the quote-verse
      while (*++c != '\"')                  // until next quote
        if (*c == '\\' && (*(c + 1) == '\"' || *(c + 1) == '\\' || *(c+1) == ';')) // watch out for pesky escapees
          append_to_string(s, *++c);
        else
          append_to_string(s, *c);
      break;
    default: // nothing cool is happening, push to string
      append_to_string(s, *c);
      break;
    }
  }
  append_to_args(a, s); // i see the end (here)
  free_string(s);       // remove temporary bucket
  return a;
}

char ***tokenize_pipeline(char **args) {

  size_t pipe_args_size = 1;
  size_t current_arg_size = 1;

  char ***args_cmd = (char ***)calloc(pipe_args_size + 1, sizeof(char **));

  for (char **s = args; *s != NULL; ++s) {
    if (!strcmp(*s, "|")) {
      args_cmd =
          (char ***)realloc(args_cmd, (++pipe_args_size + 1) * sizeof(char **));
      args_cmd[pipe_args_size - 1] = NULL;
      current_arg_size = 1;
    } else {
      args_cmd[pipe_args_size - 1] = (char **)realloc(
          args_cmd[pipe_args_size - 1], (++current_arg_size) * sizeof(char *));
      args_cmd[pipe_args_size - 1][current_arg_size - 2] = *s;
      args_cmd[pipe_args_size - 1][current_arg_size - 1] = NULL;
    }
  }

  args_cmd[pipe_args_size] = NULL;

  return args_cmd;
}

void free_pipeline_tokens(char ***pipeline_array) {
  for (char ***arr = pipeline_array; *arr != NULL; ++arr) {
    free(*arr);
  }
  free(pipeline_array);
}
