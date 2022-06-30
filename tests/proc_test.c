int main(void) {

  int fd[2];
  int fd_ex[2];

  char *cmd1[] = {"ls", "-la", NULL};
  char *cmd2[] = {"wc", "-l", NULL};
  char **pipeline1[] = {cmd1, cmd2, NULL};

  fork_exec(cmd1);
  fork_exec_pipe(cmd1, cmd2, fd);
  fork_exec_pipe_ex(cmd1, cmd2, fd_ex, "file_in", NULL , true);
  execute_pipeline(pipeline1, true);
  execute_pipeline_ex(pipeline1, true, "file_in", "file_out", false);
  return 0;
}
