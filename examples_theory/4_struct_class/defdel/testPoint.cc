#include "Point.h"

#include <iostream>

int main() {

  Point p0;
  std::cout << "-----" << std::endl;
  Point p1( 2.3, 4.5 );
  std::cout << "-----" << std::endl;
  Point p2( 6.1, 1.8 );
  std::cout << "-----" << std::endl;
  Point p3( 1.2 );
  std::cout << "-----" << std::endl;
  std::cout << p0.dist( p2 ) << std::endl;
  std::cout << p1.dist( p2 ) << std::endl;
  std::cout << p1.dist( p3 ) << std::endl;
  std::cout << &p1 << std::endl;
  return 0;

}

