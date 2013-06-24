all: dynamicarray_test linkedlist_test bst_test hashtable_test

dynamicarray_test: dynamicarray.o dynamicarray_test.c
linkedlist_test: linkedlist.o linkedlist_test.c
bst_test: bst.o bst_test.c
hashtable_test: hashtable.o hashtable_test.c
