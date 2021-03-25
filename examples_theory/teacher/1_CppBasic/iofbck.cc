
// read back 3 integer numbers from binary file

#include <iostream>
#include <fstream>

int main() {

  int i,j,k;
  std::ifstream ifile( "num.dat", std::ios::binary );
  ifile.read( reinterpret_cast<char*>( &i ), sizeof( i ) );
  ifile.read( reinterpret_cast<char*>( &j ), sizeof( j ) );
  ifile.read( reinterpret_cast<char*>( &k ), sizeof( k ) );
  std::cout << i << " " << j << " " << k << std::endl;

  return 0;

}


