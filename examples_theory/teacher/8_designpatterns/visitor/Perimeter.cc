#include "Perimeter.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

#include <cmath>

Perimeter::Perimeter(): Operation ( "perimeter" ) {
}


Perimeter::~Perimeter() {
}


void Perimeter::exec( const Triangle & t ) {
  float tW = t.width();
  float tH = t.height();
  float tC = t.base();
  float tA = sqrt( ( tW * tW ) + ( tH * tH ) );
  tW = fabs( tC - tW );
  float tB = sqrt( ( tW * tW ) + ( tH * tH ) );
  shapeP = tA + tB + tC;
  return;
}


void Perimeter::exec( const Square   & s ) {
  shapeP = 4 * s.side();
  return;
}


void Perimeter::exec( const Rectangle& r ) {
  shapeP = 2 * ( r.base() + r.height() );
  return;
}


float Perimeter::get() {
  return shapeP;
}

