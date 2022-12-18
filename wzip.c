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
void encode(FILE* fd){
  char c, prev = fgetc(fd);
  int count = 1;
  while((c = fgetc(fd)) != EOF){
    if(c == prev) {
      count++;
    } else {
      write(count,prev);
      count = 1;
    }
    prev = c;
  }
  write(count,prev);
}

int main (int argc, char *argv[]) {
  if (argc < 2) usage();
  for(int i = 1; i< argc; i++) {
    encode(fopen(argv[i],"r"));
  }
  return 0;
}
