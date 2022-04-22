#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int tokc(const char *buff);
char **tokenize(char *buff, char *sep, int tokc);
void print_args(char **tokens, int tokc);
char *trim(char *str);
int pipe_count(const char *buff);
