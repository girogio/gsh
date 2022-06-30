#include "../src/better_tokenizer.h"

int main(void) {

  char *line;

  line = strdup("ls -la | wc -l | figlet");

  Args *tokenized_line = tokenize(line);
  char ***pipeline = tokenize_pipeline(tokenized_line->args);

  print_args(tokenized_line);

  free_pipeline_tokens(pipeline);
  free_args(tokenized_line);
  free(line);

  return 0;
}