Data models: tree, list, set, relational (?), graph

wc -l *.c *.h => 358

array, list, bst, hashmap

a dictionary supports insert, delete, lookup

...linear and binary search in array

dynamic programming algo: longest common substring, LCS. ?

character strings lists...?, null character

for hash maps - impl dict, that is: insert delete lookup

trees - generalize with LCRS tree, pointer to leftmost child and right sibling.

trees - preinpostorder as arithmetic expressions, in: a + (b-c)*d, (+ a (* (- b c) d)), '3 4 +' reverse polish notation

bsts as dictionaries (adt)

so you can implement it, fine. but how do you know it works, and its complexity? test data, measure. testing and measuring _a must_.

also grok inorder postorder thingies.

interface in header, only public things, rest static.

whats up with extern?

all header files sub 20, all impls sub 100, that's 500 locs, then some tests/docs

// motivating problem: make a (name, value) table using arrays
// operations to implement
// how would you test it?
// how would you measure it to find bottlenecks?


dynamic array: (name, value) table with add and delete
linked list: (name, value) table with create, add, lookup, apply



algo design manual notes
priority queue sup? sorting helps access etc, couple of ex, data struct techniques, divide-and-conquer, randomization (qsort), explain: linear and binary search (quintessential), graphs very universal, we restrict down to trees etc with terminolgoy, adjacency list most useful, BFS/DFS to visit every edge/vertex, standard graph also: MST, shortest path (hm...), simulated annealing heuristic searches sup?, caching for recursion calls (fib), dynamic programming understand,




* Measure, cool graph of hash table perf depending on key

* Test data, something like (wrong example but principle):
while (scanf ("%s %d", name, &value) != EOF) {
￼￼￼  p = newitem(name, value);
     lsit1 = addfront(list1, p);
     list2 = addend(list2,p);
}
for (p = listl; p != NULL; p = p->next)
    printf ("%s %d\nW, p->name, p->value);

* assert, check check error returns
* test incrementally, and simple parts
* scaffold testing to mechanize it, read from input file
* test automation

* measure:
- use a profiler
- focus on hot spots
- draw a picture


http://www.lysator.liu.se/c/pikestyle.html
http://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/08DsAlg.pdf
http://cm.bell-labs.com/cm/cs/tpop/toc.html

http://sist.sysu.edu.cn/~isslxm/DSA/textbook/Skiena.-.TheAlgorithmDesignManual.pdf


/* data structures and algorithms to know by heart

   dynamic array
   linked list
   binary tree
   hash table

   linear and binary search
   DFS, pre-order and post-order
   BFS

   quicksort

   how to implement graphs, stacks and queues

   // two things oskar
   // one, print this
   // two, try to seperate into different files
   // three, three things oskar
   // three, implement them, enough yak-shaving already
*/
