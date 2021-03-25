#include "Point.h"
#include "Line.h"

#include <iostream>

int main() {

  Point p1( 2.3, 4.5 );
  std::cout << "p1: " << &p1 << std::endl;
  Point p2( 6.1, 1.8 );
  std::cout << "p2: " << &p2 << std::endl;
  Point p3( 3.3, 5.9 );
  std::cout << "p3: " << &p3 << std::endl;
  Point p4( 8.2, 2.7 );
  std::cout << "p4: " << &p4 << std::endl;
  Line l1( p1, p2 );
  Line l2( p3, p4 );
  Point pi = l1.intersect( l2 );
  std::cout << "***** intersection *****" << std::endl;
  std::cout << pi.getX() << " "
            << pi.getY() << std::endl;
  std::cout << "***** check distances *****" << std::endl;
  std::cout << l1.dist( p1 ) << " "
            << l1.dist( p2 ) << " "
            << l1.dist( pi ) << std::endl;
  std::cout << l2.dist( p3 ) << " "
            << l2.dist( p4 ) << " "
            << l2.dist( pi ) << std::endl;
  std::cout << "***** compute distances *****" << std::endl;
  std::cout << l1.dist( p3 ) << " "
            << l1.dist( p4 ) << std::endl;
  std::cout << l2.dist( p1 ) << " "
            << l2.dist( p2 ) << std::endl;            
  return 0;

}

