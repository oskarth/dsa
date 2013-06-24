#include "dynamicarray.h"

#include <assert.h>
#include <stdbool.h>

// all we gotta do is add tests for addname and delname, see that they
//  work as expected

static void test_foo() {
  assert(false && "message");
}

int main() {
  test_foo();
}
