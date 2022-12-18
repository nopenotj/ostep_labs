#include <stdio.h>
#include <stdlib.h>

void usage() {
  printf("wunzip: file1 [file2 ...]\n");
  exit(1);
}
void decode(FILE* fd) {
  int count;
  char c;
  while (1) {
    if(fread(&count, sizeof(count), 1, fd) == 0) return;
    fread(&c, sizeof(c), 1, fd);
    for(int i=0; i < count; i++) printf("%c",c);
  }
}
int main(int argc, char** argv) {
  if (argc < 2) usage();
  for (int i=1; i < argc; i++) decode(fopen(argv[i],"r"));
  return 0;
}
