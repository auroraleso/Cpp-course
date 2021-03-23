#include "Rectangle.h"
#include "Operation.h"


Rectangle::Rectangle( float b, float h ):
 Shape( "rectangle" ),
 rB( b ),
 rH( h ) {
}


Rectangle::~Rectangle() {
}


void Rectangle::exec( Operation& o ) const {
  o.exec( *this );
  return;
}


float Rectangle::base() const {
  return rB;
}


float Rectangle::height() const {
  return rH;
}

