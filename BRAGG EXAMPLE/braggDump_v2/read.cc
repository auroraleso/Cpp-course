#include <iostream>
#include <fstream>

#include "Event.h"

const Event* read( std::ifstream& file ) {

  // event pointer and identifier
  Event* ev;
  int i;

  // try to read input file
  // on success create new event
  if ( file.read( reinterpret_cast<char*>( &i ),
                                   sizeof(  i ) ) ) ev = new Event;
  // on failure return null pointer
  else return nullptr;

  // set event number
  ev->evNumber = i;

  // read and store number of points
  int n;
  file.read( reinterpret_cast<char*>( &n ), sizeof( n ) );
  ev->nPoints = n;

  // allocate array for points
  ev->eLoss = new int[n];

  // read and store all points
  for ( i = 0; i < n; ++i )
  file.read( reinterpret_cast<char*>( ev->eLoss + i ), sizeof( ev->eLoss[i] ) );

  return ev;

}

