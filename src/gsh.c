#include "proc.h"
#include "tokenizer.h"

// seperator
#include "../lib/linenoise.h"
// seperator

void completion(const char *buf, linenoiseCompletions *lc) {
  if (buf[0] == 'c') {
    linenoiseAddCompletion(lc, "clear");
    linenoiseAddCompletion(lc, "hello there");
  }
}

char *hints(const char *buf, int *color, int *bold) {
  if (!strcasecmp(buf, "hello")) {
    *color = 35;
    *bold = 0;
    return " World";
  }
  return NULL;
}

int main(int argc, char **argv) {
  char *line;
  char *prgname = argv[0];

  /* Parse options, with --multiline we enable multi line editing. */
  while (argc > 1) {
    argc--;
    argv++;
    if (!strcmp(*argv, "--multiline")) {
      linenoiseSetMultiLine(1);
      printf("Multi-line mode enabled.\n");
    } else if (!strcmp(*argv, "--keycodes")) {
      linenoisePrintKeyCodes();
      exit(0);
    } else {
      fprintf(stderr, "Usage: %s [--multiline] [--keycodes]\n", prgname);
      exit(1);
    }
  }

  linenoiseSetCompletionCallback(completion);
  linenoiseSetHintsCallback(hints);

  linenoiseHistoryLoad("history.txt");
  char **tokens;

  while ((line = linenoise("\033[1;34mgsh \033[1;32m$\033[m ")) != NULL) {
    if (line[0] != '\0' && line[0] != '/') {

      linenoiseHistoryAdd(line);           /* Add to the history. */
      linenoiseHistorySave("history.txt"); /* Save the history on disk. */

      int token_count = tokc(line);

      printf("\ntokc: [%d]\n", token_count);

      int pipec =  pipe_count(line);

      printf("\npipes: [%d]\n", pipec);

      tokens = tokenize(line, " ", token_count);


      if(!strcmp(tokens[0], "exit")){
        free(tokens);
        exit(EXIT_SUCCESS);
      }else{
        // fork_exec(tokens);       
        free(tokens);
      }


    }
    free(line);
  }
  return 0;
}

