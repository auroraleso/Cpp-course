
// starting from 3 int read from the keyboard create the pointers
// to the first, second or third one if the third one is respectively
// bigger than 30, comprised between 20 and 30 or smaller than 20.

#include <iostream>

void f() {
  int i = 12;
  int j = 23;
  int* p = &i; // "p" is the address of "i"
  std::cout << *p << std::endl;
  *p = 24;
  p = &j;
  std::cout << i << " " << *p << std::endl;
  return;
}

int main() {

  f();

  int i,j,k;
  std::cin >> i >> j >> k;
  std::cout << i << " " << j << " " << k << std::endl;

  int *p; // also valid: int *p;
  if ( k >= 30 ) {
    p = &i;
  }
  else if ( k < 30 && k >= 20 ) {
    p = &j;
  }
  else {
    p = &k;
  }

  std::cout << p << " " << *p << std::endl;

  return 0;

}
