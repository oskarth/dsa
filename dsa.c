// data structures and algorithms to know by heart
//
// lists - array list, linked list, stack, queue; mappings; trees; graph
// traversal - BFS, DFS; and more.
//
// no error handling here
//
// Credits: casablanca @SO (array list)

#include <stdlib.h>
#include <stdio.h>

// array list

typedef struct {
  int *array;
  size_t used, size;
} Array;

void initArray(Array *a, size_t initSize) {
  a->array = (int *)malloc(initSize * sizeof(int));
  a->used = 0;
  a->size = initSize;
}

// TODO: insert at position, shift by one
void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2; /* dynamic resize */
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

printArray() { /* TODO */ }
deleteArray() { /* TODO */ }
locateArray() { /* TODO */ }

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

// TODO: linked list
// TODO: stack
// TODO: queue
// TODO: mapping / hash table
// TODO: binary tree
// TODO: tree traversal









// main function
int main() {

  // array list play
  Array a;
  initArray(&a, 5);
  for (int i = 0; i < 100; i++)
    insertArray(&a, i);
  printf("%d\n", a.array[9]);
  printf("%d\n", (int)a.used);
  freeArray(&a);
}
