
// modify to read from file and write both to screen and file

// read 3 integer numbers from file and write them onto the screen
// and onto a second file

#include <iostream>
#include <fstream>

int main() {

  int i,j,k;
  std::ifstream ifile( "num.txt" );
  std::ofstream ofile( "num.dat", std::ios::binary );
  ifile >> i >> j >> k;
  i *= 2;
  j *= 3;
  k *= 4;
  std::cout << i << " " << j << " " << k << std::endl;
  ofile.write( reinterpret_cast<char*>( &i ), sizeof( i ) );
  ofile.write( reinterpret_cast<char*>( &j ), sizeof( j ) );
  ofile.write( reinterpret_cast<char*>( &k ), sizeof( k ) );

  return 0;

}


