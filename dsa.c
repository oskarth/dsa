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

/* a linked list of nodes*/

typedef struct Node Node;
struct Node {
  char *name;
  int value;
  Node *next; /* in list */
};

/* newitem: create new item from name and value*/
Node *newitem(char *name, int value) {
  Node *newp;

  newp = (Node *) malloc(sizeof(Node));
  newp->name = name;
  newp->value = value;
  newp->next = NULL;
  return newp;
}

/* addfront: add newp to front of listp */
// usage: nvlist = addfront(nvlist, newitem("smiley", 0x263A));
Node *addfront(Node *listp, Node *newp) {
  newp->next = listp;
  return newp;
}

/* addend: add newp to end of listp*/
Node *addend(Node *listp, Node *newp) {
  Node *p;

  if (listp == NULL)
    return newp;
  for (p = listp; p->next != NULL; p = p->next)
    ;
  p->next = newp;
  return listp;
}

/* lookup: sequential search for name in listp */
Node *lookup(Node *listp, char *name) {
  for( ; listp != NULL; listp = listp->next)
    if (strcmp(name, listp->name) == 0)
      return listp;
  return NULL; /* no match */
}

/* apply: execute fn for each element of listp */
void apply(Node *listp, void (*fn)(Node*, void*), void *arg) {
  for ( ; listp != NULL; listp = listp->next)
    (*fn)(listp, arg); /* call the function */
}

/* printlist: print name and value using format in arg */
// usage: apply(list, printlist, "%s: %x\n");
void printlist(Node *p, void *arg) {
  char *fmt;
  fmt = (char *) arg;
  printf(fmt, p->name, p->value);
}

/* inccounter: increment counter *arg */
void inccounter(Node *p, void *arg) {
  int *ip;
  /* p is unused */
  ip = (int *) arg;
  (*ip)++;
}

/* freeall: free all elements of listp */
void freeall(Node *listp) {
  Node *next;
  for ( ; listp != NULL; listp = next) {
    next = listp->next;
    /* assumes name is freed elsewhere */
    free(listp);
      }
}

/* delitem: delete first "name" from listp */
Node *delitem(Node *listp, char *name) {
  Node *p, *prev;
  prev = NULL;
  for (p = listp; p != NULL; p = p->next) {
    if (strcmp(name, p->name) == 0) {
      if (prev == NULL)
        listp = p->next;
      else
        prev->next = p->next;
      free(p);
      return listp;
    }
    prev = p;
  }
  printf("delitem: %s not in list", name);
  return NULL;
}

int main() {

  // Linked list stuff
  printf("Linked list for you.\n");
  Node *list;
  int n = 0;
  list = newitem("Pike", 5);
  list = addfront(list, newitem("Kernighan", 3));
  apply(list, printlist, "%s: %x\n");
}
