#include <iostream>
#include <iomanip>
#include "BST.h"

using namespace std;

int main(int argc, char **argv) {
  BST b;
  int i;
  for (i = 1; i < argc; ++i) {
    b.insert_node(atoi(argv[i]));
  }

  b.print_all();

  return 0;
}