
// read 3 integer numbers from file and write them onto the screen
// and onto a second file

#include <iostream>
#include <fstream>

int main() {

  int i,j,k;
  std::ifstream ifile( "num.txt" );
  std::ofstream ofile( "num.out" );
  ifile >> i >> j >> k;
  i *= 2;
  j *= 3;
  k *= 4;
  std::cout << i << " " << j << " " << k << std::endl;
  ofile << i << " " << j << " " << k << std::endl;

  return 0;

}


