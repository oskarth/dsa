#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* typedef struct Nameval Nameval; */
/* struct Nameval { */
/*   char *name; */
/*   int value; */
/*   Nameval *next; /\* in list *\/ */
/* }; */

/* newitem: create newitem from name and value */
Nameval *newitem(char *name, int value) {
  Nameval *newp;

  newp = (Nameval *) malloc(sizeof(Nameval));
  newp->name = name;
  newp->value = value;
  newp->next = NULL;
  return newp;
}

/* addfront: add newp to front of listp */
Nameval *addfront(Nameval *listp, Nameval *newp) {
  newp->next = listp;
  return newp;
}

/* lookup: sequential search for name in listp */
Nameval *lookup(Nameval *listp, char *name) {
  for( ; listp != NULL; listp = listp->next)
    if (strcmp(name, listp->name) == 0)
      return listp;
  return NULL; /* no match */
}

/* apply: execute fn for each element of listp */
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg) {
  for ( ; listp != NULL; listp = listp->next)
    (*fn)(listp, arg); /* call the function */
}

/* printnv: print name and value using format in arg */
void printnv(Nameval *p, void *arg) {
  char *fmt;

  fmt = (char *) arg;
  printf(fmt, p->name, p->value);
}

/* inccounter: increment counter *arg */
void inccounter(Nameval *p, void *arg) {
  int *ip;

  ip = (int *) arg;
  (*ip)++;
}

/* freeall: free all elements of listp */
void freeall(Nameval *listp) {
  Nameval *next;

  for ( ; listp != NULL; listp = next) {
    next = listp->next;
    /* assumes name is freed elsewhere */
  }
}

/* delitem: delete first "name" from listp */
Nameval *delitem(Nameval *listp, char *name) {
  Nameval *p, *prev;

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
  return NULL; /* not a very graceful return */
}

/* int main() { */
/*   int n = 0; */
/*   Nameval *nvlist; */

/*   nvlist = newitem("Ritchie", 3); */
/*   nvlist = addfront(nvlist, newitem("Kernighan", 2)); */
/*   nvlist = addfront(nvlist, newitem("Pike", 5)); */
/*   nvlist = delitem(nvlist, "Ritchie"); */

/*   apply(nvlist, printnv, "%s: %x\n"); */
/*   apply(nvlist, inccounter, &n); */
/*   printf("%d elements in nvlist\n", n); */
/* } */
