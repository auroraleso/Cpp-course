#include "Array.h"

using namespace std;

template <>
Array<bool>::Array( unsigned int n ):
  eltn( n ),
  cont( new bool[eltn] ) {
  std::cout << "created... this is special!! " << cont << std::endl;
}
