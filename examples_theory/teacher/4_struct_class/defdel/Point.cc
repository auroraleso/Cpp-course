#include "Point.h"

#include <iostream>
#include <cmath>

Point::Point( float d ):
  Point( x, x ) {
  std::cout << "new point " << this << " delegated" << std::endl;
}


Point::Point( float x, float y ):
 xp( x ),
 yp( y ) {
  std::cout << "new point " << this << std::endl;
}

Point::~Point() {
}


float Point::getX() const {
  return xp;
}

float Point::getY() const {
  return yp;
}

float Point::dist( const Point& p ) const {
  return sqrt( pow( xp - p.xp, 2 ) +
               pow( yp - p.yp ,2 ) );
}

