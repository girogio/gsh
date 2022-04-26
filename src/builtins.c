#include "builtins.h"
#include "parser.h"
#include <stdlib.h>

static struct builtin_command builtin_list[] = {{"exit", &exit_shell},
                                                {"cd", &change_dir},
                                                {"cwd", &print_cwd},
                                                {"ver", &show_info},
                                                {"clear", &clear_screen}};

int exit_shell(char **tokens) {
  for (char **p = tokens; *p != NULL; ++p)
    free(*p);
  free(tokens);
  return -2; // return this if exiting
}

int change_dir(char **args) {

  int argc = 0;

  for (char **p = args; *p != NULL; ++p) {
    argc++;
  }

  if (argc > 2) {
    printf("cd: too many arguments\n");
  } else if (argc == 1) {
    if (getenv("HOME"))
      chdir(getenv("HOME"));
  } else if (chdir(args[1]) == -1)
    perror("cd failed");

  return EXIT_SUCCESS; // return this if succeded
}

int print_cwd() {
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("%s\n", cwd);
  } else {
    perror("getcwd failed");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS; // return this if succeded
}

int clear_screen(char **args) {
  printf("\e[1;1H\e[2J\n");
  return EXIT_SUCCESS;
}

int show_info(char **args) {

  puts("  _   _                 _          _ _ ");
  puts("| |_(_)_ __  _   _ ___| |__   ___| | |");
  puts("| __| | '_ \\| | | / __| '_ \\ / _ \\ | |");
  puts("| |_| | | | | |_| \\__ \\ | | |  __/ | |");
  puts(" \\__|_|_| |_|\\__, |___/_| |_|\\___|_|_|");
  puts("             |___/     ");

  puts("\n\nVersion: 1.0");
  puts("Author: Giorgio Grigolo");
  puts("Description: A simple shell, aims to supply basic functionality that a "
       "shell would have. Before you ask me: I might not be able to get past "
       "Iudex Gundyr but I can code a shell. "

       "😎\n\n\nPlease consider supporting this project as I would love to a "
       "good grade.");
  return 0;
}

int execute_builtin(char **args) {
  for (int i = 0; i < sizeof(builtin_list) / sizeof(builtin_list[0]);
       i++) {                                     // check for builtins
    if (!strcmp(builtin_list[i].name, args[0])) { // has to be exactly equal
      return builtin_list[i].method(args);
    }
  }
  return -1; // return this if noting found
}