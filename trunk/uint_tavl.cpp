#ifndef _UINT_TAVL_CPP_
#define _UINT_TAVL_CPP_
#include "uint_tavl.h"

uint_tavl::uint_tavl() {
  tree = tavl_create (&comp_addr, NULL, &tavl_allocator_default);
}

uint_tavl::~uint_tavl() {
  tavl_destroy (tree, &uint_destroy);
}

struct tavl_traverser *uint_tavl::begin() {
  iterator tree_iter = new tavl_traverser;
  tavl_t_first(tree_iter, tree);
  return tree_iter;
}

struct tavl_traverser *uint_tavl::end() {
  return NULL;
}

unsigned int& uint_tavl::operator [](const unsigned int &first) {
  unsigned int *probe_elem = new unsigned int[2];
  probe_elem[0] = first;
  unsigned int **ret = (unsigned int **)tavl_probe(tree, (void *)probe_elem);
  if (*ret != probe_elem)
    delete[] probe_elem;
  return (*ret)[1];
}

#endif
