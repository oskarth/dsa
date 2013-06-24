/* bst.h: a binary search tree implemenation to store name-value pairs */

typedef struct Nameval Nameval;
struct Nameval {
  char *name;
  int value;
  Nameval *left; /* lesser */
  Nameval *right; /* greater */
};

Nameval *newitem(char *name, int value); /* create newitem from name and value */
Nameval *insert(Nameval *treep, Nameval *newp); /* insert newp in treep, return treep */
Nameval *lookup(Nameval *treep, char *name); /* look up name in tree treep */
Nameval *nrlookup(Nameval *treep, char *name); /* non-recursively look up name in tree treep */
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg); /* inorder application of fn to treep */
void applypostorder(Nameval *treep, void (*fn)(Nameval *, void*), void *arg); /* postorder application of fn to treep */
