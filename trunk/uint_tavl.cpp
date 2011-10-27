#ifndef _UINT_TAVL_CPP_
#define _UINT_TAVL_CPP_
#include "uint_tavl.h"

/* returns 0 if the iterator is pointed to NULL */
unsigned int first(const tavl_traverser &iter) {
  struct tavl_node *node = iter.tavl_node;
  if (node != NULL) {
    return ((unsigned int *)node->tavl_data)[0];
  }
  return 0;
}

unsigned int second(const tavl_traverser &iter) {
  struct tavl_node *node = iter.tavl_node;
  if (node != NULL) {
    return ((unsigned int *)node->tavl_data)[1];
  }
  return 0;
}

struct tavl_traverser operator ++(tavl_traverser &a, int) {
  struct tavl_traverser ret = a;
  tavl_t_next(&a);
  return ret;
}

struct tavl_traverser operator --(tavl_traverser &a, int) {
  struct tavl_traverser ret = a;
  tavl_t_prev(&a);
  return ret;
}

int operator ==(const struct tavl_traverser& a, const struct tavl_traverser& b) {
  return (a.tavl_table == b.tavl_table && a.tavl_node == b.tavl_node);
}

int operator !=(const struct tavl_traverser& a, const struct tavl_traverser& b) {
  return (a.tavl_table != b.tavl_table || a.tavl_node != b.tavl_node);
}

uint_tavl::uint_tavl() {
  tree = tavl_create (&comp_addr, NULL, &tavl_allocator_default);
}

uint_tavl::~uint_tavl() {
  tavl_destroy (tree, &uint_destroy);
}

struct tavl_traverser uint_tavl::begin() {
  iterator tree_iter;
  tavl_t_first(&tree_iter, tree);
  return tree_iter;
}

/* the end of a tavl is pointed to NULL */
struct tavl_traverser uint_tavl::end() {
  iterator tree_iter;
  tree_iter.tavl_table = tree;
  tree_iter.tavl_node = NULL;
  return tree_iter;
}

struct tavl_traverser uint_tavl::upper_bound(unsigned int upper) {
  iterator ret_iter;
  ret_iter.tavl_table = tree;
  struct tavl_node *trav = tree->tavl_root, *ret = NULL;
  while (1) {
    if (*(unsigned int *)trav->tavl_data > upper) {
      ret = trav;
      if (trav->tavl_tag[0] == TAVL_CHILD)
        trav = trav->tavl_link[0];
      else {
        ret_iter.tavl_node = ret;
        return ret_iter;
      }
    }/*
    else if (*(unsigned int *)tavl_t_cur(trav) == upper) {
      if (trav == last)
        return NULL;
      tavl_t_next(trav);
      return trav;
    }*/
    else {
      if (trav->tavl_tag[1] == TAVL_CHILD)
        trav = trav->tavl_link[1];
      else {
        ret_iter.tavl_node = ret;
        return ret_iter;
      }
    }
  }
}

void uint_tavl::erase(iterator erase_iter) {
  unsigned int *erase_elem = (unsigned int *)erase_iter.tavl_node;
  if (erase_elem != NULL) {
    tavl_delete(tree, (const void *)erase_elem);
    delete[] erase_elem;
  }
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
