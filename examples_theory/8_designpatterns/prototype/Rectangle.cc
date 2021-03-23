#include "Rectangle.h"
#include "ShapeFactory.h"

#include <sstream>

using namespace std;

class RectanglePrototypeRegister {
 public:
  RectanglePrototypeRegister() {
    ShapeFactory::registerShape( new Rectangle( 1.0, 1.0 ) );
  }
};
static RectanglePrototypeRegister rpr;

Rectangle::Rectangle( float b, float h ):
 Shape( "rectangle" ),
 rB( b ),
 rH( h ) {
}


Rectangle::~Rectangle() {
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


// create a new Rectangle with dimensions as described in "info"
Shape* Rectangle::clone( const std::string& info ) const {
  stringstream sstr( info );
  float b;
  float h;
  sstr >> b >> h;
  return new Rectangle( b, h );  
}

