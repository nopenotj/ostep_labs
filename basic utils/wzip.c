#include <stdio.h>
#include <stdlib.h>

void usage() { 
  printf("wzip: file1 [file2 ...]\n");
  exit(1);
}
void write(int count, char prev) {
  fwrite(&count, sizeof(int), 1, stdout);
  fwrite(&prev, sizeof(char), 1, stdout);
}

int main (int argc, char *argv[]) {
  if (argc < 2) usage();
  int i = 1;
  FILE* fd = fopen(argv[i],"r");
  char c, prev = fgetc(fd);
  int count = 1;
  while(1){
    // Get next Character
    if ((c = fgetc(fd)) == EOF) {
      if(!(++i < argc)) break;
      fd = fopen(argv[i],"r");
      continue;
    }
    // Compress characters
    if(c == prev) {
      count++;
    } else {
      write(count,prev);
      count = 1;
    }
    prev = c;
  }
  write(count,prev);
  return 0;
}
