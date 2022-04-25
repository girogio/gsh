#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_pipeline(char ***pipeline_args);

void process_input(char *line);

bool is_redir_token(const char *s);
bool has_invalid_char(char *s);
bool redir_file_valid(char **array);
int redirection_type(char *token);
