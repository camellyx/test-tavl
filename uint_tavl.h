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

class uint_tavl {
public:
	uint_tavl();
	~uint_tavl();
	
	typedef tavl_traverser* iterator;
	
	iterator begin();
	iterator end();
	unsigned int &operator [](const unsigned int &first);
private:
	struct tavl_table *tree;
};

#include "uint_tavl.cpp"
#endif
