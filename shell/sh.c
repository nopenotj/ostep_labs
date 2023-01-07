#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void c_handler(int i) { return; }

int main(int argc, char *argv[]) {
  signal(SIGINT, c_handler);

  char *s = NULL;
  size_t len = 0;
  while (1) {

    printf("jsh> ");
    int l = getline(&s, &len, stdin);
    char *tofree = s;

    // Parse user input
    char *args[30];
    int argc = 0;
    char *found;

    while ((found = strsep(&s, " \n")) != NULL) args[argc++] = found;
    args[argc - 1] = NULL;

    // Check against builtin cmds
    if (!strcmp(args[0], "exit")) {
      free(tofree);
      exit(0);
    } else if (!strcmp(args[0], "cd")) {
      chdir(args[1]);
    } else {
      // Process Command
      char full_path[255];
      sprintf(full_path, "%s%s", "/bin/", args[0]);
      if (access(full_path, X_OK) == -1) printf("jsh: command not found: %s\n", args[0]);
      if (fork() > 0) {
        // parent
        wait(NULL);
      } else {
        // child
        execv(full_path, args);
      }
    }

    // Clean up memory
    free(tofree);
  }
  return 0;
}
