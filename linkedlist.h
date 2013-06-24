/* linkedlist.h: name-value pairs using a linked list */

typedef struct Nameval Nameval;
struct Nameval {
  char *name;
  int value;
  Nameval *next; /* in list */
};

Nameval *newitem(char *name, int value); /* create newitem from name and value */
Nameval *addfront(Nameval *listp, Nameval *newp); /* add newp to front of listp */
Nameval *lookup(Nameval *listp, char *name); /* sequential search for name in listp */
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg); /*execute fn for each element of listp */
void printnv(Nameval *p, void *arg); /* print name and value using format in arg */
void inccounter(Nameval *p, void *arg); /* increment counter *arg */
void freeall(Nameval *listp); /* free all elements of listp */
Nameval *delitem(Nameval *listp, char *name); /* delete first "name" from listp */
