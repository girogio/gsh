
#include "../lib/linenoise.h"
#include "parser.h"

int update_prompt(char *PS1) {
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    perror("getcwd failed");
    return EXIT_FAILURE;
  }

  PS1[0] = '\0';

  strcat(PS1, cwd);

  strcat(PS1, " $ ");

  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  char *line;

  linenoiseHistoryLoad("history.txt");

  char cwd[PATH_MAX];

  char PS1[64 + PATH_MAX];

  update_prompt(PS1);

  while ((line = linenoise(PS1)) != NULL) {

    if (line[0] != '\0') {

      linenoiseHistoryAdd(line);           // Add to the history.
      linenoiseHistorySave("history.txt"); // Save the history on disk.

      process_input(line);
      update_prompt(PS1);
    }
    free(line);
  }
  return 0;
}
