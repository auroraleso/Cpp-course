#include <iostream>

#include "Event.h"

void dump( const Event& ev ) {

  // write event number and number of points
  std::cout << ev.evNumber << ' '
            << ev.nPoints;

  // write all points
  int i;
  for ( i = 0; i < ev.nPoints; ++i ) std::cout << ' ' << ev.eLoss[i];
  std::cout << std::endl;

  return;

}

