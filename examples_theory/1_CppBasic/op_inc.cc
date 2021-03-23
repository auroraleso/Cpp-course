
// pre/post increment

#include <iostream>
#include <cmath>

int main() {

  int i;
  int j = 0;
  int k = 0;
  for ( i = 0; i < 10; ++i ) {
    std::cout << j << " " << k;
    if ( j++ == 3 ) std::cout << " j at three";
    if ( ++k == 7 ) std::cout << " k at seven";
    std::cout << std::endl;
  }

  return 0;

}
