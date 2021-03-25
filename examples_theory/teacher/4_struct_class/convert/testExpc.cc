#include "Pluto.h"

#include <iostream>

void f( int i ) {
  std::cout << "f: " << i << std::endl;
}


int main() {

  Pluto p( 9 );

  // automatic conversion of an object "Pluto" to an int
  // not working because Pluto::operator int() constructor is explicit
//  f( p );
  f( static_cast<int>( p ) );

  Pluto q( 7 );
//  int n = q;
  int n = static_cast<int>( q );
  std::cout << "n: " << n << std::endl;

  return 0;

}

