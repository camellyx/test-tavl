#include "avl/tavl.h"
#include "avl/tavl.c"

int comp_addr(const void *a, const void *b, void *) {
  if (*(unsigned int *)a == *(unsigned int *)b)
    return 0;
  else if (*(unsigned int *)a > *(unsigned int *)b)
    return 1;
  else
    return -1;
}

void uint_destroy(void *ptr, void *) {
  unsigned int *dptr = (unsigned int *)ptr;
  delete[] dptr;
}

int main() {
  struct tavl_table *tree;
  /* create a tree */
  tree = tavl_create (&comp_addr, NULL, &tavl_allocator_default);
  
  /* probe elements */
  unsigned int *probe_elem = new unsigned int[2];
  probe_elem[0] = 1;
  probe_elem[1] = 2;
  printf("%d\n", probe_elem);
  unsigned int **ret = (unsigned int **)tavl_probe(tree, (void *)probe_elem);
  printf("%d\n", *ret);
  
  probe_elem = new unsigned int[2];
  probe_elem[0] = 1;
  probe_elem[1] = 4;
  printf("%d\n", probe_elem);
  ret = (unsigned int **)tavl_probe(tree, (void *)probe_elem);
  printf("%d\n", *ret);
  
  /* delete a tree */
  tavl_destroy(tree, &uint_destroy);
  return 0;
}
