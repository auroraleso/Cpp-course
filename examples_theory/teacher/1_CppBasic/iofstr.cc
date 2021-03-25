
// read an integer number number and write it to a string

// read another number from the same string stream

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

int main() {

  int i;
  std::cin >> i;
  std::stringstream sstr;
  sstr << " a " << i << " " << i*2;
  std::cout << "now write string" << std::endl;
  std::cout << sstr.str() << std::endl;
  std::cout << "now clear string" << std::endl;
  sstr.str( "" ); // clear the output string
  std::cout << "now write string" << std::endl;
  sstr << " b " << i << " " << i*3;
  std::cout << sstr.str() << std::endl;

  int j;
  int k;
  int l;

  std::stringstream sstr1; // declare sstr1
  sstr1.str( "12" );       // set sstr1
  sstr1 >> j;              // read from sstr1

  std::stringstream sstr2( "34" ); // declare and set sstr2
  sstr2 >> k;                      // read from sstr2

  sstr1.clear();                   // go back to sstr1, reset
  sstr1.str( "56" );               // set sstr1 again
  sstr1 >> l;                      // read from sstr1

  std::cout << j << " " << k << " " << l << std::endl;

  std::cout << "=============" << std::endl;

  float x;
  std::cin >> x;
  char cs[1000];
  sprintf( cs, "***%12.6f***\n", sqrt( x ) );
  std::cout << cs << std::endl;

  return 0;

}


