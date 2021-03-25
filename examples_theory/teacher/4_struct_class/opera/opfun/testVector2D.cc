#include "Vector2D.h"

#include <iostream>

int main() {

  Vector2D u(  3.4, 4.5 );
  Vector2D v( -1.6, 6.9 );

  Vector2D s = u + v;
  u *= 3;
// equivalent to
//  Vector2D s = operator+( u, v );
//  operator*=( u, 3 );

  std::cout << s.getX() << " " << s.getY() << std::endl;
  std::cout << u.getX() << " " << u.getY() << std::endl;

  return 0;

}

