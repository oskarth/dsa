#include "dynamicarray.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void test_basics() {
  int i;
  Nameval nv1 = {.name = "Ritchie", .value = 10};
  Nameval nv2 = {.name = "Kernighan", .value = 5};
  Nameval nv3 = {.name = "Pike", .value = 3};

  addname(nv1);
  assert(addname(nv2) == 1 && "test_add()");
  addname(nv3);
  delname("Kernighan");
  assert(strcmp(nvtab.nameval[1].name, "Pike") == 0 && "test_add()");
}

int main() {
  test_basics();
}
