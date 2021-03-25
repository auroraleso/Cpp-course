#include "Square.h"


Square::Square( float s ):
  sS( s ) {
}


Square::~Square() {
}


// specific function for squares: get side
float Square::side() const {
  return sS;
}


// compute area for squares
float Square::area() const {
  return sS * sS;
}


// compute perimeter for squares
float Square::perimeter() const {
  return 4 * sS;
}

