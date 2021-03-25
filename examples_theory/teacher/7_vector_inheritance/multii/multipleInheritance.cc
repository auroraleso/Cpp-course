#include "Derived.h"
#include <iostream>
using namespace std;

int main() {

  Derived* d = new Derived( 5, 7 );
  cout << d << endl;

  // Derived class inherits function f from Base class through
  // IntermediateA and IntermediateB, so that a simple call is ambiguous
//  d->f( 2 );
//  d->f( 3 );
  // to disambiguate the call must be explicitly sent through
  // IntermediateA or IntermediateB
  d->IntermediateA::f( 2 );
  d->IntermediateB::f( 3 );

  return 0;

}

