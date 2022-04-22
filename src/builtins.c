#include "builtins.h"

typedef int (*builtin_t)(char **);

struct builtin_command {
  char *name;
  builtin_t method;
};

int exit_shell(char **args) {
  printf("exiting");
   return 0; 
}

int change_dir(char **args) {
  chdir(args[2]);
  print_cwd(NULL);
  return 0;
}

int print_cwd(char **args) {
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s\n", cwd);
   } else {
       perror("Failed to getcwd()");
       return 1;
   }
  return 0;
}

int show_info(char **args) {
  
  puts("  _   _                 _          _ _ ");
  puts("| |_(_)_ __  _   _ ___| |__   ___| | |");
  puts("| __| | '_ \\| | | / __| '_ \\ / _ \\ | |");
  puts("| |_| | | | | |_| \\__ \\ | | |  __/ | |");
  puts(" \\__|_|_| |_|\\__, |___/_| |_|\\___|_|_|");
  puts("             |___/     ");
  puts("\n\nVersion: 1.0");
  puts("Giorgio Grigolo");
  puts("Description: A simple shell, aimed to supply basic functionality that any general shell would be assumed to have.");
  puts("\n\nI might not be able to get past Iudex Gundyr but I can code a shell 😎.\nPlease consider supporting this project, as I need good grades.");
  return 0;
}

static struct builtin_command builtin_list[] = {
  {"exit", &exit_shell},
  {"cd", &change_dir},
  {"cwd", &print_cwd},
  {"ver", &show_info}
};

int main(int argc, char **args) {
  for (int i = 0; i < sizeof(builtin_list) / sizeof(builtin_list[0]); i++) {
    if (!strncmp(builtin_list[i].name, args[1], strlen(args[1]))) {
      int result = builtin_list[i].method(args);
    }
  }
  return 0;
}