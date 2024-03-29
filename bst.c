#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*newitem: create newitem from name and value */
Nameval *newitem(char *name, int value) {
  Nameval *newp;

  newp = (Nameval *) malloc(sizeof(Nameval));
  newp->name = name;
  newp->value = value;
  newp->left = NULL;
  newp->right = NULL;
  return newp;
}

/* insert: insert newp in treep, return treep */
Nameval *insert(Nameval *treep, Nameval *newp) {
  int cmp;

  if (treep == NULL)
    return newp;
  cmp = strcmp(newp->name, treep->name);
  if (cmp == 0)
    printf("insert: duplicate entry %s ignored", newp->name);
  else if (cmp < 0)
    treep->left = insert(treep->left, newp);
  else
    treep->right = insert(treep->right, newp);
  return treep;
}

/* lookup: look up name in tree treep */
Nameval *lookup(Nameval *treep, char *name) {
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
Nameval *nrlookup(Nameval *treep, char *name) {
  int cmp;

  while(treep != NULL) {
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

/* applyinorder: inorder application of fn to treep */
void applyinorder(Nameval *treep,
                  void (*fn)(Nameval*, void*), void *arg) {
  if (treep ==  NULL)
    return;
  applyinorder(treep->left, fn, arg);
  (*fn)(treep, arg);
  applyinorder(treep->right, fn, arg);
}

/* applypostorder: postorder application of fn to treep */
void applypostorder(Nameval *treep,
                    void (*fn)(Nameval *, void*), void *arg) {
  if (treep == NULL)
    return;
  applypostorder(treep->left, fn, arg);
  applypostorder(treep->right, fn, arg);
  (*fn)(treep, arg);
}
