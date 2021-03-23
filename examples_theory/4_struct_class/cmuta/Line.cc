#include "Line.h"

#include "Point.h"
#include <cmath>
#include <cfloat>

float Line::tolerance = 1.0e-05;

Line::Line( const Point& p1, const Point& p2 ) {
  float x1 = p1.getX();
  float y1 = p1.getY();
  float x2 = p2.getX();
  float y2 = p2.getY();
  float dx = x1 - x2;
  float dy = y1 - y2;
  if ( fabs( dx ) > fabs( dy ) ) {
    a = -dy / dx;
    b = 1.0;
  }
  else {
    b = -dx / dy;
    a = 1.0;
  }
  c = -( ( a * x1 ) + ( b * y1 ) );
}

Line::~Line() {
}


Point Line::intersect( const Line& l ) const {
  float det = ( a * l.b ) - ( b * l.a );
  float chk = pow( a, 2 ) + pow( b, 2 ) + pow( l.a, 2 ) + pow( l.b, 2 );
  if ( fabs( det / chk ) < tolerance ) return Point( FLT_MAX, FLT_MAX );
  return Point( ( ( b * l.c ) - ( c * l.b ) ) / det,
                ( ( c * l.a ) - ( a * l.c ) ) / det );
}

