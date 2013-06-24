/* hashtable.h: a hash table implementation of name-value pairs */

typedef struct Nameval Nameval;
struct Nameval {
  char *name;
  int value;
  Nameval *next; /* in chain */
};

enum { NHASH = 1000, MULTIPLIER = 31 }; /* array size and hash value */

Nameval *symtab[NHASH]; /* a symbol table */

unsigned int hash(char *str); /* compute hash value of string */
Nameval *lookup(char *name, int create, int value); /* find name in symtab, with optional create */
