#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>




void c_handler(int i) {
  return;
}


int main(int argc, char* argv[]) {
  signal(SIGINT, c_handler);

  char* s = NULL;
  size_t len = 0;
  while(1){
    printf("jsh> ");
    getline(&s, &len, stdin);
    printf("jsh: command not found: %s\n", s);
    if(!strcmp(s, "exit\n")) exit(0);
  }
  return 0;
}
