#include "avl/tavl.h"
#include "avl/tavl.c"

int comp_addr(const void *a, const void *b, void *) {
  return *(unsigned int *)a > *(unsigned int *)b;
}

int main() {
  struct tavl_table *tree;
  /* create a tree */
  tree = tavl_create (&comp_addr, NULL, &tavl_allocator_default);
  
  /* probe elements */
  unsigned int *probe_elem = new unsigned int(1);
  //printf("%d\n", (int)probe_elem);
  unsigned int **ret = (unsigned int **)tavl_probe(tree, (void *)probe_elem);
  //printf("%d\n", *ret);
  
  /* delete elements */
  unsigned int *del_elem = (unsigned int *)tavl_delete(tree, (const void *)probe_elem);
  //printf("%d\n", del_elem);
  delete del_elem;
  
  /* add elements */
  unsigned int *add_elem = new unsigned int(1);
  assert( tavl_insert(tree, (void *)add_elem) == NULL);
  del_elem = (unsigned int *)tavl_delete(tree, (const void *)probe_elem);
  
  /* add lots of elements */
  for (int i=0;i<100;i++) {
    add_elem = new unsigned int(i);
    assert( tavl_insert(tree, (void *)add_elem) == NULL);
  }
  
  /* inintialize a traverser (no use at all??)*/
  struct tavl_traverser *tree_iter = new tavl_traverser;
  tavl_t_init(tree_iter, tree);
  
  /* find the first */
  unsigned int *iter_elem = (unsigned int *)tavl_t_first(tree_iter, tree);
  //printf("%d\n", *iter_elem);
  return 0;
}
