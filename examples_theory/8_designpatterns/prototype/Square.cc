#include "Square.h"
#include "ShapeFactory.h"

#include <sstream>

using namespace std;

class SquarePrototypeRegister {
 public:
  SquarePrototypeRegister() {
    ShapeFactory::registerShape( new Square( 1.0 ) );
  }
};
static SquarePrototypeRegister spr;

Square::Square( float s ):
 Shape( "square" ),
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


// create a new Square with dimensions as described in "info"
Shape* Square::clone( const std::string& info ) const {
  stringstream sstr( info );
  float s;
  sstr >> s;
  return new Square( s );
}

