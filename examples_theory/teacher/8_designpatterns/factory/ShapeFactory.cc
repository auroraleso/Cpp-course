#include "ShapeFactory.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include <iostream>
#include <sstream>

using namespace std;

ShapeFactory::ShapeFactory() {
}


ShapeFactory::~ShapeFactory() {
}


Shape* ShapeFactory::create() {
  // ask for a new shape from standard input
  cout << "enter shape > " << flush;
  int maxLength = 1000;
  char line[maxLength];
  // get info from standard input, reset stream at end of input (ctrl-d)
  if ( cin.getline( line, maxLength ) ) return create( line );
  else                                  cin.clear();
  return 0;
}


Shape* ShapeFactory::create( const char* line ) {

  // accept request with form "shape dimension1 [dimension2]" e.g.
  // triangle 1.3 4.5

  // remove leading blanks
  while ( *line == ' ' ) ++line;
  // skip empty lines
  if ( !*line ) return create();
  // extract shape
  string s = line;
  int n = s.find( " " );
  s = s.substr( 0, n );
  // extract parameters
  const string p = line + n;
  stringstream sstr( p );

  // create shape
  if ( s == "triangle" ) {
    float a;
    float b;
    float c;
    sstr >> a >> b;
    return ( sstr >> c ? new Triangle( a, b, c ) : new Triangle( a, b ) );
  }
  else
  if ( s == "square" ) {
    float a;
    sstr >> a;
    return new Square( a );
  }
  else
  if ( s == "rectangle" ) {
    float b;
    float h;
    sstr >> b >> h;
    return new Rectangle( b, h );
  }

  // if unknown shape requested, ask again
  cout << "unknown shape" << endl;
  return create();

}

