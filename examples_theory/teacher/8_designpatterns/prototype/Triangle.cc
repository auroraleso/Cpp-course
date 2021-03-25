#include "Triangle.h"
#include "ShapeFactory.h"

#include <sstream>
#include <cmath>

using namespace std;

class TrianglePrototypeRegister {
 public:
  TrianglePrototypeRegister() {
    ShapeFactory::registerShape( new Triangle( 1.0, 1.0 ) );
  }
};
static TrianglePrototypeRegister tpr;

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


// create a new Triangle with dimensions as described in "info"
Shape* Triangle::clone( const std::string& info ) const {
  stringstream sstr( info );
  float a;
  float b;
  float c;
  sstr >> a >> b;
  return ( sstr >> c ? new Triangle( a, b, c ) : new Triangle( a, b ) );
}

