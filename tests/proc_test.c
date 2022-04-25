#include "../src/proc.c"

int main() {

  int fd[2];
  int fd_ex[2];

  char *cmd1[] = {"ls", "-la", NULL};
  char *cmd2[] = {"wc", "-l", NULL};

  fork_exec_pipe(cmd1, cmd2, fd);
  fork_exec_pipe_ex(cmd1, cmd2, fd_ex, "bruh_in", NULL , true);

  return 0;
}
