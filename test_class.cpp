#include "uint_tavl.h"

int main() {
  uint_tavl tavl;
  uint_tavl::iterator tavl_iter = tavl.begin();
  for (int i=2;i<10;i++) {
    tavl[i] = 100-i;
  }
  tavl_iter = tavl.begin();
  uint_tavl::iterator tmp;
  tmp.tavl_table = tavl.tree;
  tmp.tavl_node = NULL;
  printf("%d\n", tavl_iter != tmp);
  printf("%d\n", second(tavl_iter));
  for (uint_tavl::iterator i=tavl.begin();
                           i!=tavl.end();i++) {
    printf("%d\n", second(i));
  }
  for (int i=0;i<12;i++) {
    printf("%d %d\n", i, first(tavl.upper_bound(i)));
  }
  tmp = tavl.upper_bound(5);
  printf("%d %d\n", first(tmp), second(tmp));
  second(tmp) = 1;
  printf("%d %d\n", first(tmp), second(tmp));
  return 0;
}
