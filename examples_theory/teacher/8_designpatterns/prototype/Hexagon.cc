#include "Hexagon.h"
#include "ShapeFactory.h"

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class HexagonPrototypeRegister {
 public:
  HexagonPrototypeRegister() {
    ShapeFactory::registerShape( new Hexagon( 1.0 ) );
  }
};
static HexagonPrototypeRegister hpr;

Hexagon::Hexagon( float s ):
 Shape( "hexagon" ),
 hS( s ) {
}

Hexagon::~Hexagon() {
}


// specific function for squares: get side
float Hexagon::side() const {
  return hS;
}


// compute area for squares
float Hexagon::area() const {
  return hS * hS * sqrt( 6.75 );
}


// compute perimeter for squares
float Hexagon::perimeter() const {
  return 6 * hS;
}


// create a new Hexagon with dimensions as described in "info"
Shape* Hexagon::clone( const std::string& info ) const {
  stringstream sstr( info );
  float s;
  sstr >> s;
  return new Hexagon( s );
}

