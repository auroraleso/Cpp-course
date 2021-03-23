
// write a function to comupte factorial

#include <iostream>
#include <cmath>

unsigned int fact( unsigned int n ) {
  if ( n ) return n * fact( n - 1 );
  return 1;
}

int main() {

  unsigned
  int n;
  for ( n = 0; n < 13; ++n ) std::cout << n << "! = "
                                       << fact( n ) << std::endl; 
  return 0;

}
