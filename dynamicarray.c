#include "dynamicarray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* typedef struct Nameval Nameval; */
/* struct Nameval { */
/*   char *name; */
/*   int value; */
/* }; */

/* struct NVTable { */
/*   int nval; /\* number of name value pairs *\/ */
/*   int max; /\* max capacity of array *\/ */
/*   Nameval *nameval; /\* array of name value pairs *\/ */
/* } nvtab; */

/* enum { NVINIT = 1, NVGROW = 2 }; */

/* addname: add new name and value to nvtab */
int addname(Nameval newname) {
  Nameval *nvp;

  if (nvtab.nameval == NULL) { /* first time */
    nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
    if (nvtab.nameval == NULL) return -1;
    nvtab.max = NVINIT;
    nvtab.nval = 0;
  }
  else if (nvtab.nval >= nvtab.max) { /* grow */
    nvp = (Nameval *) realloc(nvtab.nameval,
                              ((NVGROW*nvtab.max) * sizeof(Nameval)));
    if (nvp == NULL) return -1;
    nvtab.max *= NVGROW;
    nvtab.nameval = nvp;
  }
  nvtab.nameval[nvtab.nval] = newname;
  return nvtab.nval++;
}

/* delname: delete first matching nameval from nvtab */
int delname(char *name) {
  int i;

  for (i = 0; i < nvtab.nval; i++)
    if (strcmp(nvtab.nameval[i].name, name) == 0) {
      memmove(nvtab.nameval+i, nvtab.nameval+i+1,
              (nvtab.nval-(i+1)) * sizeof(Nameval));
      nvtab.nval--;
      return 1;
    }
  return 0;
}

/* int main() { */
/*   int i; */
/*   Nameval nv1 = {"Pike", 3}; */
/*   Nameval nv2 = {"Kernighan", 5}; */
/*   Nameval nv3 = {"Ritchie", 4}; */

/*   addname(nv1); */
/*   addname(nv2); */
/*   delname("Pike"); */
/*   addname(nv3); */

/*   for (i = 0; i < nvtab.nval; i++) */
/*     printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value); */
/* } */
