#pragma once
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenize(char *line, char *sep);
void free_tokens(char **tokenized_array);

char ***tokenize_pipeline(char **args);
void free_pipeline_tokens(char ***pipeline);
