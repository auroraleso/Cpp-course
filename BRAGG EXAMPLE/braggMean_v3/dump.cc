#include <iostream>

#include "Event.h"

void dump( const Event& ev ) {

  // write event number and number of points
  unsigned int n = ev.dataSize();
  std::cout << ev.eventNumber() << ' '
            << n;

  // write all points
  unsigned int i;
  for ( i = 0; i < n; ++i ) std::cout << ' ' << ev.energy( i );
  std::cout << std::endl;

  return;

}

