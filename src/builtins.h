#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

typedef int (*builtin_t)(char **);

struct builtin_command {
  char *name;
  builtin_t method;
};

int execute_builtin(char **args);

int exit_shell(char **);
int change_dir(char **);
int print_cwd();
int show_info(char **);
int clear_screen(char **);