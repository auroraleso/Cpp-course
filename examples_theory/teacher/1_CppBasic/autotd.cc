
// C++11 code
// read 3 integer numbers from the keyboard and write them onto the screen

#include <iostream>
#include <cmath>

int f(double x) {
  return 2*lround(x);
}
int main() {
  auto i=f(3.7);
  decltype(i) j;
  j=i*i;
  std::cout << i << " " << j << std::endl;
  return 0;
}

