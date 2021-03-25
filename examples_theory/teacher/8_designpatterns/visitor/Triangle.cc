#include "Triangle.h"
#include "Operation.h"

#include <cmath>

Triangle::Triangle( float b, float h ):
 Shape( "triangle" ),
 sA( sqrt( ( b * b / 4 ) + ( h * h ) ) ),
 sB( sA ),
 sC( b ) {
}


Triangle::Triangle( float a, float b, float c ):
 Shape( "triangle" ),
 sA( a ),
 sB( b ),
 sC( c ) {
}


Triangle::~Triangle() {
}


void Triangle::exec( Operation& o ) const {
  o.exec( *this );
  return;
}


float Triangle::base() const {
  return sC;
}


float Triangle::height() const {
  float hp = ( sA + sB + sC ) / 2;
  return sqrt( 4 * hp * ( hp - sA ) * ( hp - sB ) * ( hp - sC ) ) / sC;
}


float Triangle::width() const {
  float z = ( sA > sB ? sA : sB );
  float h = height();
  return sqrt( ( z * z ) - ( h * h ) );
}

