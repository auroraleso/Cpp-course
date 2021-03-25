#include "ShapeFactory.h"
#include "Shape.h"
#include <iostream>
#include <sstream>
#include <dlfcn.h>

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
  return nullptr;
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
  // load additional library
  if ( s == "load" ) {
    line += n;
    // remove leading blanks
    while ( *line == ' ' ) ++line;
    // load dynamic library
    cout << "load library ---" << line << "----" << endl;
    void* p = dlopen( line, RTLD_LAZY );
    if ( p == nullptr ) cout << "load failed" << endl;
    // ask again
    return create();
  }
  // extract parameters
  const string p = line + n;

  // get shape prototype map
  static std::map<std::string,const Shape*>& sp = *shapePrototype();
  // find required shape prototype
  map<string,const Shape*>::const_iterator iter = sp.find( s );
  map<string,const Shape*>::const_iterator iend = sp.end();

  // if found create new shape from prototype, else ask again
  if ( iter == iend ) {
    cout << "unknown shape" << endl;
    return create();
  }
  return iter->second->clone( p );

}


void ShapeFactory::registerShape( const Shape* shape ) {
  std::map<std::string,const Shape*>& sp = *shapePrototype();
  sp[shape->name()] = shape;
  return;
}


std::map<std::string,const Shape*>* ShapeFactory::shapePrototype() {
  static std::map<std::string,const Shape*> sp;
  return &sp;
}

