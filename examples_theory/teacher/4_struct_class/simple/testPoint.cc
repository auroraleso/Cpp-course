#include "Point.h"

#include <iostream>

int main() {

  Point p1( 2.3, 4.5 );
  Point p2( 6.1, 1.8 );
  std::cout << p1.dist( p2 ) << std::endl;
  std::cout << &p1 << std::endl;
  return 0;

}

