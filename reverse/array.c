#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char** l;
  int size;
  int cap;
} array;
array new_arr() { return (array){.l=NULL,.size = 0, .cap=0}; }
void push(array* a, char* item) {
  a->size++;
  if (!(a->size < a->cap)) {
    a->cap = 2* a->size;
    a->l = realloc(a->l, sizeof(char *) * a->cap);
    if (a->l == NULL) {
      fprintf(stderr,"malloc failed\n");
      exit(1);
    }
  }
  a->l[a->size - 1] = item;
}
char* get(array* a, int i) { return a->l[i]; }

