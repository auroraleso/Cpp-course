#include "Shape.h"
#include "Operation.h"
#include <vector>
#include <iostream>

using namespace std;

void func( vector<Shape*>& shape,
           vector<Operation*>& operation ) {
  for ( const Shape* s: shape ) {
    for ( Operation* o: operation ) {
      s->exec( *o );
      cout << s->name() << " has "
           << o->name() << " "
           << o->get() << endl;
    }
  }
}

