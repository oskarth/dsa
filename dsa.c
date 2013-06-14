// data structures and algorithms to know by heart
//
// lists - array list, linked list, stack, queue; mappings; trees; graph
// traversal - BFS, DFS; and more.

#include <stdio.h>

#define MAX 5

// array list

/* struct arraylist { */
/*   int list[MAX]; */
/*   int last; // where init this? */
/* }; */

int saveto(int lst[]) {
  int i, c;

  while ((c = getchar()) != EOF)
    for (i = 0; i < MAX; i++) // don't know end, this is a potential problem.
      scanf("%d", &lst[i]); // save the scanned digit to the _address_

  return 0;
}

int write(int lst[]) {
  int i;

  for (i = 0; i < MAX; i++)
    printf("%d\n", lst[i]);

  return 0;
}

int main() {
  int lst[MAX];

  saveto(lst);
  write(lst);

  return 0;
}

// linked list
