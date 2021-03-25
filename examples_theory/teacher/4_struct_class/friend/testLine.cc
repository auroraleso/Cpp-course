#include "Point.h"
#include "Line.h"

#include <iostream>

int main() {

  Point p1( 2.3, 4.5 );
  Point p2( 6.1, 1.8 );
  Point p3( 3.3, 5.9 );
  Point p4( 8.2, 2.7 );
  Line l1( p1, p2 );
  Line l2( p3, p4 );
  Point pi = l1.intersect( l2 );
  std::cout << pi.getX() << " "
            << pi.getY() << std::endl;
  std::cout << l1.dist( p1 ) << " "
            << l1.dist( p2 ) << " "
            << l1.dist( pi ) << std::endl;
  std::cout << l2.dist( p3 ) << " "
            << l2.dist( p4 ) << " "
            << l2.dist( pi ) << std::endl;
  std::cout << l1.dist( p3 ) << " "
            << l1.dist( p4 ) << std::endl;
  std::cout << l2.dist( p1 ) << " "
            << l2.dist( p2 ) << std::endl;            
  return 0;

}

