#include "Shape.h"
#include "ShapeFactory.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {

  // an array of geometric shapes
  vector<Shape*> shape;

  // create shapes
  Shape* s;
  while ( ( s = ShapeFactory::create() ) != nullptr ) shape.push_back( s );

  cout << endl;
  cout << "************" << endl;

  // loop over shapes
  for ( const auto s: shape ) s->print();

  // delete all the shapes
  for ( const auto s: shape ) delete s;

  return 0;

}


