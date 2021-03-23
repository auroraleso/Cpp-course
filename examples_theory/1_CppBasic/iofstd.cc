
// read a floating point number and write it with different formats
// using C-style

#include <iostream>
#include <cstdio>
#include <cmath>

int main() {

  float x;
  std::cin >> x;
  printf( "123456789012345678901234567890\n" );
  printf( "***%12.4f***\n", x );
  printf( "***%12.6f***\n", sqrt( x ) );

  return 0;

}
