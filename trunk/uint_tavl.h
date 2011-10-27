#ifndef _UINT_TAVL_H_
#define _UINT_TAVL_H_

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

unsigned int first(const tavl_traverser &iter);
unsigned int second(const tavl_traverser &iter);
struct tavl_traverser operator ++(tavl_traverser &a, int);
struct tavl_traverser operator --(tavl_traverser &a, int);
int operator ==(const struct tavl_traverser& a, const struct tavl_traverser& b);
int operator !=(const struct tavl_traverser& a, const struct tavl_traverser& b);

class uint_tavl {
public:
  uint_tavl();
  ~uint_tavl();
  
  typedef tavl_traverser iterator;
  
  iterator begin();
  iterator end();
  iterator upper_bound(unsigned int upper);
  void erase(iterator erase_iter);
  unsigned int &operator [](const unsigned int &first);
//private:
  struct tavl_table *tree;
};

#include "uint_tavl.cpp"
#endif
