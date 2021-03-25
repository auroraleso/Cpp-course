#include <iostream>
#include <fstream>

int read( std::ifstream& file,
          int* eLoss ) {

  // read number of points
  int n;
  file.read( reinterpret_cast<char*>( &n ), sizeof( n ) );

  // read all points
  int i;
  for ( i = 0; i < n; ++i )
  file.read( reinterpret_cast<char*>( eLoss + i ), sizeof( eLoss[i] ) );

  return n;

}

