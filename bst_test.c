#include "bst.h"

#include <assert.h>
#include <stdbool.h>

static void test_foo() {
  assert(true && "message");
}

int main() {
  test_foo();
}
