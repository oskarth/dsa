#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* a growable array of items */

typedef struct Item Item;
struct Item {
  char *name;
  int value;
};

struct Table {
  int nval; /* current number of values */
  int max; /* allocated number of values */
  Item *item; /* array of items (name-value pairs) */
} table;

enum { INIT = 1, GROW = 2 };

/* addname: add new name and value to table */
int addname(Item newname) {
  Item *ip;

  if (table.item == NULL) { /* first time */
    table.item = (Item *) malloc(INIT * sizeof(Item));
    if (table.item == NULL)
      return -1;
    table.max = INIT;
    table.nval = 0;
  } else if (table.nval >= table.max) { /* grow */
    ip = (Item *) realloc(table.item, (GROW*table.max) * sizeof(Item));
    if (ip == NULL)
      return -1;
    table.max *= GROW;
    table.item = ip;
  }
  table.item[table.nval] = newname;
  return table.nval++;
}

/* delname: remove first matching item from table */
int delname(char *name) {
  int i;

  for (i = 0; i < table.nval; i++)
    if (strcmp(table.item[i].name, name) == 0) {
      memmove(table.item+i, table.item+i+1, (table.nval-(i+1)) * sizeof(Item));
      table.nval--;
      return 1;
      }
  return 0;
}

int main() {

}
