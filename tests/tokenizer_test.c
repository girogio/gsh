#include "../src/tokenizer.c"

int main(void) {

  char *line;

  line = strdup("ls -la | wc -l | figlet");

  char **tokenized_line = tokenize(line, " ");

  char ***pipeline = tokenize_pipeline(tokenized_line);

  free_pipeline_tokens(pipeline);
  free_tokens(tokenized_line);
  free(line);

  return 0;
}