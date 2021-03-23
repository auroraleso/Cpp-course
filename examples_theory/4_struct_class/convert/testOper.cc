#include "Pippo.h"

#include <iostream>

void f( int i ) {
  std::cout << "f: " << i << std::endl;
}


int main() {

  Pippo p( 9 );

  // automatic conversion of an object "Pippo" to an int
  f( p );

  Pippo q( 7 );
  int n = q;
  std::cout << "n: " << n << std::endl;

  return 0;

}

