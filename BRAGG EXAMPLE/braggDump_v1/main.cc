#include <iostream>
#include <fstream>

int  read( std::ifstream& file,
           int* eLoss );
void dump( int evNumber,
           int nPoints,
           int* eLoss );

int main( int argc, char* argv[] ) {

  // open input file
  const char* name = argv[1];
  std::ifstream file( name, std::ios::binary );

  // declare event variables
  int evNumber;
  int nPoints;
  int eLoss[200];

  // loop over events
  while ( file.read( reinterpret_cast<char*>( &evNumber ),
                                      sizeof(  evNumber ) ) ) {
    nPoints = read( file, eLoss );
    dump( evNumber, nPoints, eLoss );
  }

  return 0;

}

