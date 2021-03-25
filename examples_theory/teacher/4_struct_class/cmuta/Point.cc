#include "Point.h"

#include <iostream>
#include <cmath>

Point::Point( float x, float y ):
 xp( x ),
 yp( y ),
 dp( -1.0 ) {
  std::cout << "new point" << std::endl;
}

Point::~Point() {
}


float Point::getX() const {
  return xp;
}

float Point::getY() const {
  return yp;
}

float Point::dist() const {
  if ( dp < 0.0 ) dp = sqrt( pow( xp, 2 ) + pow( yp, 2 ) );
  return dp;
}

float Point::dist( const Point& p ) const {
  return sqrt( pow( xp - p.xp, 2 ) +
               pow( yp - p.yp ,2 ) );
}

