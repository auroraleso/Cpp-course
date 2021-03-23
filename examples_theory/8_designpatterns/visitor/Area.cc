#include "Area.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"


Area::Area(): Operation ( "area" ) {
}


Area::~Area() {
}


void Area::exec( const Triangle & t ) {
  shapeA = t.base() * t.height() / 2;
  return;
}


void Area::exec( const Square   & s ) {
  float side = s.side();
  shapeA = side * side;
  return;
}


void Area::exec( const Rectangle& r ) {
  shapeA = r.base() * r.height();
  return;
}


float Area::get() {
  return shapeA;
}

