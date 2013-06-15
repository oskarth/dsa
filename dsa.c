/* data structures and algorithms to know by heart
   30 pages by Kernighan and Pike in TPOP */

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

/* llookup: sequential search for name in listp */
Node *llookup(Node *listp, char *name) {
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

/* binary search tree */

typedef struct Tnode Tnode;
struct Tnode {
  char *name;
  int value;
  Tnode *left; /* lesser */
  Tnode *right; /* greater */
};

/* insert: insert newp in treep, return treep */
Tnode *insert(Tnode *treep, Tnode *newp) {
  int cmp;
  if (treep == NULL)
    return newp;
  cmp = strcmp(newp->name, treep->name);
  if (cmp == 0)
    printf("inset: duplicate entry %s ignored", newp->name);
  else if (cmp < 0)
    treep->left = insert(treep->left, newp);
  else
    treep->right = insert(treep->right, newp);
  return treep;
}

/* lookup: look up name in tree treep */
Tnode *lookup(Tnode *treep, char *name) {
  int cmp;
  if (treep == NULL)
    return NULL;
  cmp = strcmp(name, treep->name);
  if (cmp == 0)
    return treep;
  else if (cmp < 0)
    return lookup(treep->left, name);
  else
    return lookup(treep->right, name);
}

/* nrlookup: non-recursively look up name in tree treep */
Tnode *nrlookup(Tnode *treep, char *name) {
  int cmp;
  while (treep != NULL) {
    cmp = strcmp(name, treep->name);
    if (cmp == 0)
      return treep;
    else if (cmp < 0)
      treep = treep->left;
    else
      treep = treep->right;
  }
  return NULL;
}

/* applyinorder: inorder application of fnto treep
   usage example: applyinorder(treep, printlist?, "%s: %x\n"); */
void applyinorder(Tnode *treep, void (*fn)(Tnode *, void*), void *arg) {
  if (treep == NULL)
    return;
  applyinorder(treep->left, fn, arg);
  (*fn)(treep, arg);
  applyinorder(treep->right, fn, arg);
}

/* applypostorder: postorder application of fn to treep */
void applypostorder(Tnode *treep, void (*fn)(Tnode *, void*), void *arg) {
  if (treep == NULL)
    return;
  applypostorder(treep->left, fn, arg);
  applypostorder(treep->right, fn, arg);
  (*fn)(treep, arg);
}

/* hash table */

// a hash table is an array of lists
// so the element type is the same as for list, that is a a Node
// constant-time lookup, insertion and deletion

enum { NHASH = 1000, MULTIPLIER = 37 };

/* hash: compute hash value of string */
unsigned int hash(char *str) {
  unsigned int h;
  unsigned char *p;
  h = 0;
  for (p = (unsigned char *) str; *p != '\0'; p++)
    h = MULTIPLIER * h + *p;
  return h % NHASH;
}

Node *symtab[NHASH]; /* a symbol table */

/* hashlookup: find name in symtab, with optional create */
Node *hashlookup(char *name, int create, int value) {
  int h;
  Node *sym;

  h = hash(name);
  for (sym = symtab[h]; sym != NULL; sym = sym->next)
    if (strcmp(name, sym->name) == 0)
      return sym;
  if (create) {
    sym = (Node *) malloc(sizeof(Node));
    sym->name = name; /* assumed allocated elsewhere */
    sym->value = value;
    sym->next = symtab[h];
    symtab[h] = sym;
  }
  return sym;
}

// algorithms

// searching

/* arraylookup: sequential search for word in array */
int arraylookup(char *word, char *array[]) {
  int i;
  for (i = 0; array[i] != NULL; i++)
    if (strcmp(word, array[i]) == 0)
      return i;
  return -1;
}

/* lookup: binary search for name in tab; return index */
int bslookup(char *name, Node tab[], int ntab) {
  int low, high, mid, cmp;
  low = 0;
  high = ntab - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    cmp = strcmp(name, tab[mid].name);
    if (cmp < 0)
      high = mid - 1;
    else if (cmp > 0)
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

// sorting

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* quicksort: sort v[0]..v[n-1] into increasing order */
void quicksort(int v[], int n) {
  int i, last;
  if (n <= 1) /* nothing to do */
    return;
  swap(v, 0, rand() % n); /* move pivot elem to v[0] */
  last = 0;
  for (i = 1; i < n; i++) /* partition */
    if (v[i] < v[0])
      swap(v, ++last, i);
  swap(v, 0, last); /* restore pivot */
  quicksort(v, last); /* recursively sort */
  quicksort(v+last+1, n-last-1); /* each port */
}

// sorting with library and custom comparison function

// usage: char *str[N] and qsort(str, N, sizeof(str[0]), scmp);

/* scmp: string compare of *p1 and *p2 */
int scmp(const void *p1, const void *p2) {
  char *v1, *v2;
  v1 = *(char **) p1;
  v2 = *(char **) p2;
  return strcmp(v1, v2);
}



int main() {
  // TODO: add more test data

  // Linked list stuff
  printf("Linked list for you.\n");
  Node *list;
  int n = 0;
  list = newitem("Pike", 5);
  list = addfront(list, newitem("Kernighan", 3));
  apply(list, printlist, "%s: %x\n");
}
