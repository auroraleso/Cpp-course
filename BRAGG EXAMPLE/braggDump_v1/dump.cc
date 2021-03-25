#include <iostream>

void dump( int evNumber,
           int nPoints,
           int* eLoss ) {

  // write event number and number of points
  std::cout << evNumber << ' '
            << nPoints;

  // write all points
  int i;
  for ( i = 0; i < nPoints; ++i ) std::cout << ' ' << eLoss[i];
  std::cout << std::endl;

  return;

}

