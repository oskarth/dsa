#include <stdio.h>

#define MAXLEN 100

struct arraylist {
  int list[MAXLEN];
  int last; // this doesn't work
};

int end(struct arraylist lst) {
  return lst.last;
}

int main() {
  printf("Compiles.\n");
}
