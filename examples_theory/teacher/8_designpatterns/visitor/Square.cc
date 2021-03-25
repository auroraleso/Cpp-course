#include "Square.h"
#include "Operation.h"


Square::Square( float s ):
 Shape( "square" ),
 sS( s ) {
}


Square::~Square() {
}


void Square::exec( Operation& o ) const {
  o.exec( *this );
  return;
}


float Square::side() const {
  return sS;
}

