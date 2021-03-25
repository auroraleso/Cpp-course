#include <iostream>

int i = 0; // visible by all functions
static
int j = 0; // visible in this translation unit only
void f() {
  std::cout << "f:i=" << ++i << std::endl;
  std::cout << "f:j=" << ++j << std::endl;
  std::cout << "------" << std::endl;
}


int main() {

  while ( i < 10 ) f();
  return 0;

}

