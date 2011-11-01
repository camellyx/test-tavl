#include "uint_tavl.h"

int main() {
  uint_tavl tavl;
  tavl[0] = -1;
  tavl[0x9028a68] = -1;
  tavl[0x9028f4f] = -1;
  tavl[0xff9af310] = -1;
  tavl[0xff9af312] = -1;
  tavl[0xf5a0531a] = -1;
  tavl[0xf5a0531b] = -1;
  tavl.dfs();
  return 0;
}
