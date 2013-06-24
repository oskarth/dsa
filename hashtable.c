#include "hashtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* hash: compute hash value of string */
unsigned int hash(char *str) {
  unsigned int h;
  unsigned char *p;

  h = 0;
  for (p = (unsigned char *) str; *p != '\0'; p++)
    h = MULTIPLIER * h + *p;
  return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval *lookup(char *name, int create, int value) {
  int h;
  Nameval *sym;

  h = hash(name);
  for (sym = symtab[h]; sym != NULL; sym = sym->next)
    if (strcmp(name, sym->name) == 0)
      return sym;
  if (create) {
    sym = (Nameval *) malloc(sizeof(Nameval));
    sym->name = name; /* assumed allocated elsewhere */
    sym->value = value;
    sym->next = symtab[h];
    symtab[h] = sym;
  }
  return sym;
}
