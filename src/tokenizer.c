#include "tokenizer.h"

char *trim(char *str) {
  char *end;

  // Trim leading space
  while (isspace((unsigned char)*str))
    str++;

  if (*str == 0) // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end))
    end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int tokc(const char *buff) {
  int count = 0, inword = 0;
  do
    switch (*buff) {
    case '\0':
    case ' ':
    case '\t':
    case '\n':
    case '\r': // TODO others?
      if (inword) {
        inword = 0;
        count++;
      }
      break;
    default:
      inword = 1;
    }
  while (*buff++ != 0);
  return count;
}

char **tokenize(char *buff, char *sep, int tokc) {

  char **tokens = (char **)calloc(tokc + 1, sizeof(char *));

  tokens[tokc] = NULL;

  char *p = strtok(buff, sep);
  int i = 0;
  while (p != NULL) {
    tokens[i++] = trim(p);
    p = strtok(NULL, sep);
  }

  return tokens;
}

int pipe_count(const char *buff){

  int pipec = 0;

  for (int i = 0; i < strlen(buff); i++)
    if (buff[i] == '|')
      pipec++;

  return pipec;
}

void print_args(char **tokens, int tokc) {
  printf("tokens: [");
  for (int i = 0; i <= tokc; i++) {
    if (i == tokc)
      printf("%s", tokens[i]);
    else {
      printf("%s, ", tokens[i]);
    }
  }
  printf("]\n\n");
}

char ***tokenize_args(char **piped_array, int pipec) {
  char ***pipeline = (char ***)calloc(pipec + 1, sizeof(char **));

  for (int i = 0; i < pipec; i++) {
    pipeline[i] = tokenize(piped_array[i], " ", tokc(piped_array[i] + 1));
    print_args(pipeline[i], tokc(piped_array[i]) + 1);
  }

  return pipeline;
}

// int main() {
//   char args[] = "ls -la |  grep file | more   | wc -l ";

//   int argc = tokpipec(args);
//   printf("%d\n", argc);
//   char **bruh = tokenize_pipe(args, "|", argc);
//   print_args(bruh, argc);
//   char ***bruhhh = tokenize_args(bruh, argc);

//       // printf("%d", tokenize_pipes(bruh, tokenc));

//       return 0;
// }
