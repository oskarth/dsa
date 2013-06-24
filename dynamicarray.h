/* dynamicarray.h: a dynamic array of name-value pairs */

typedef struct Nameval Nameval;
struct Nameval {
  char *name;
  int value;
};

struct NVTable {
  int nval; /* number of name value pairs */
  int max; /* max capacity of array */
  Nameval *nameval; /* array of name value pairs */
} nvtab;

enum { NVINIT = 1, NVGROW = 2 }; /* inital array size and growth rate */

int addname(Nameval newname); /* add new name and value to nvtab */
int delname(char *name); /* delete first matching nameval from nvtab */
