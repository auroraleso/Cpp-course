#include <iostream>

void f() {
  static
  int n = 0;
  int m = 0;
  std::cout << ++m << " " << ++n << std::endl;
  return;
}

int main() {

  int i;
  for ( i = 0; i < 10; ++i ) f();

  return 0;

}

