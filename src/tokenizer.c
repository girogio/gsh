#include "tokenizer.h"

char **tokenize(char *line, char *sep) {
  char **array = malloc(sizeof(char *));

  if (array) {
    size_t n = 1;

    char *token = strtok(line, sep);

    while (token) {
      char **tmp = realloc(array, (n + 1) * sizeof(char *));

      if (tmp == NULL)
        break;

      array = tmp;
      ++n;

      array[n - 2] = malloc(strlen(token) + 1);
      if (array[n - 2] != NULL)
        strcpy(array[n - 2], token);

      token = strtok(NULL, sep);
    }

    array[n - 1] = NULL;
  }

  return array;
}

#ifdef DEBUG
void print_tokens(char **array) {

  printf("args: [ ");

  for (char **p = array; *p != NULL; ++p) {
    printf("\"");

    printf("%s", *p);

    if (*(p + 1) == NULL)
      printf("\"");
    else
      printf("\", ");
  }

  printf(" ]\n");
}
#endif

void free_tokens(char **array) {
  for (char **p = array; *p; ++p)
    free(*p);
  free(array);
}

char ***tokenize_pipeline(char **args) {

  size_t pipe_args_size = 1;
  size_t current_arg_size = 1;

  char ***args_cmd = (char ***)calloc(pipe_args_size + 1, sizeof(char **));

  for (char **s = args; *s != NULL; ++s) {
    if (!strcmp(*s, "|")) {
      args_cmd = realloc(args_cmd, (++pipe_args_size + 1) * sizeof(char **));
      current_arg_size = 1;
    } else {
      args_cmd[pipe_args_size - 1] = (char **)realloc(args_cmd[pipe_args_size - 1], (++current_arg_size) * sizeof(char *));
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