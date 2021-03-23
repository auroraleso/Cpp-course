#include "Triangle.h"

#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle( float b, float h ):
 sA( sqrt( ( b * b / 4 ) + ( h * h ) ) ),
 sB( sA ),
 sC( b ) {
  cout << "create Triangle from base and height" << endl;
}


Triangle::Triangle( float a, float b, float c ):
 sA( a ),
 sB( b ),
 sC( c ) {
  cout << "create Triangle from sides" << endl;
}


Triangle::~Triangle() {
  cout << "delete Triangle" << endl;
}


// specific function for triangles: get base
float Triangle::base() const {
  return sC;
}


// specific function for triangles: get height
float Triangle::height() const {
  float hp = perimeter() / 2;
  return sqrt( 4 * hp * ( hp - sA ) * ( hp - sB ) * ( hp - sC ) ) / sC;
}


// compute area for triangles
float Triangle::area() const {
  float hp = perimeter() / 2;
  return sqrt( hp * ( hp - sA ) * ( hp - sB ) * ( hp - sC ) );
}


// compute perimeter for triangles
float Triangle::perimeter() const {
  return sA + sB + sC;
}

