#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "array.c"
#include <string.h>
void usage() {
  printf("usage: reverse <input> <output>\n");
  exit(1);
}
int main(int argc, char* argv[]) {
  if (argc >3 || argc < 2) usage();

  FILE* fd = fopen(argv[1], "r");
  FILE* out = argc == 3 ? fopen(argv[2], "w") : stdout;

  array arr = new_arr();
  char* line = NULL;
  size_t len = 0;
  ssize_t nread;

  while((nread = getline(&line, &len, fd)) != -1) push(&arr, strdup(line));
  for(int i=arr.size - 1; i > -1; i--) fprintf(out,"%s",get(&arr,i));

  return 0;
}
