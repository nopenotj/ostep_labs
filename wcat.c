#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  for(int i = 1; i < argc; i++) {
    FILE* f = fopen(argv[i], "r");
    if (f == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    char buff[50];
    char* p;
    while(1) {
      p = fgets(buff,50,f);
      if (p == NULL) break;
      printf("%s",buff);
    }
  }
  return 0;
}
