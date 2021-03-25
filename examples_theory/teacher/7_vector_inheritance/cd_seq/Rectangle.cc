#include "Rectangle.h"

#include <iostream>
using namespace std;

Rectangle::Rectangle( float b, float h ):
  rB( b ),
  rH( h ) {
  cout << "create Rectangle" << endl;
}


Rectangle::~Rectangle() {
  cout << "delete Rectangle" << endl;
}


// specific function for rectangles: get base
float Rectangle::base() const {
  return rB;
}


// specific function for rectangles: get height
float Rectangle::height() const {
  return rH;
}


// compute area for rectangles
float Rectangle::area() const {
  return rB * rH;
}


// compute perimeter for rectangles
float Rectangle::perimeter() const {
  return 2 * ( rB + rH );
}

