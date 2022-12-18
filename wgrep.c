#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void usage() {
  printf("wgrep: searchterm [file ...]\n");
  exit(1);
}

void print_match(FILE* f, char* searchterm) {
  if(f == NULL) {
    printf("wgrep: cannot open file\n");
    exit(1);
  }
  char * line = NULL;
  size_t len;
  ssize_t nread;
  while ((nread = getline(&line, &len, f)) != -1) {
    if(strstr(line, searchterm) != NULL) printf("%s",line);
  }
  free(line);
}

int main (int argc, char *argv[])
{
  if (argc < 2) usage();
  char* searchterm = argv[1];
  // Read stdin
  if (argc == 2) {
    print_match(stdin, searchterm);
    exit(0);
  }
  // Read files
  for (int i = 2; i < argc; i++) {
    print_match(fopen(argv[i], "r"), searchterm);
  }
  return 0;
}
