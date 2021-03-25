#include <iostream>

int main() {

  int* p;

  int i;
  for ( i = 0; i < 10; ++i ) {
    int j = 0;
    static
    int k = 0;
    std::cout << ++j << " " << ++k << std::endl;
    p = &k;
  }

  std::cout << "final: " << *p << std::endl;

  return 0;

}

