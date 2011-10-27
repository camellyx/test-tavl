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
  delete dptr;
}

int main() {
  struct tavl_table *tree;
  /* create a tree */
  tree = tavl_create (&comp_addr, NULL, &tavl_allocator_default);
  
  /* probe elements */
  unsigned int *probe_elem = new unsigned int[2];
  printf("%d\n", probe_elem);
  unsigned int **ret = (unsigned int **)tavl_probe(tree, (void *)probe_elem);
  printf("%d\n", *ret);
  probe_elem = new unsigned int[2];
  printf("%d\n", probe_elem);
  
  /* delete elements */
  unsigned int *del_elem = (unsigned int *)tavl_delete(tree, (const void *)probe_elem);
  printf("%d\n", del_elem == NULL);
  delete del_elem;
  
  /* add elements */
  unsigned int *add_elem = new unsigned int[2];
  assert( tavl_insert(tree, (void *)add_elem) == NULL);
  del_elem = (unsigned int *)tavl_delete(tree, (const void *)probe_elem);
  
  /* add lots of elements */
  for (int i=0;i<10;i++) {
    add_elem = new unsigned int(10-i);
    //printf("%d\n", *add_elem);
    assert( tavl_insert(tree, (void *)add_elem) == NULL);
  }
  
  /* inintialize a traverser (no use at all??)*/
  struct tavl_traverser *tree_iter = new tavl_traverser;
  tavl_t_init(tree_iter, tree);
  
  /* find the first */
  unsigned int *iter_elem = (unsigned int *)tavl_t_first(tree_iter, tree);
  //printf("%d\n", *iter_elem);
  
  /* traverse forward */
  for (int i=0;i<9;i++) {
    iter_elem = (unsigned int *)tavl_t_next(tree_iter);
    //printf("%d %d\n", *iter_elem, iter_elem);
    //printf("%d %d\n", *(unsigned int *)tavl_t_cur(tree_iter), tavl_t_cur(tree_iter));
  }
  
  /* traverse backward */
  for (int i=0;i<9;i++) {
    iter_elem = (unsigned int *)tavl_t_prev(tree_iter);
    //printf("%d %d\n", *iter_elem, iter_elem);
  }
  
  /* find the last */
  iter_elem = (unsigned int *)tavl_t_last(tree_iter, tree);
  //printf("%d\n", *iter_elem);
  
  /* delete a tree */
  tavl_destroy(tree, &uint_destroy);
  return 0;
}
