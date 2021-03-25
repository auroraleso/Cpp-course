#include <iostream>
#include <fstream>

#include "Event.h"

using namespace std;

const Event* read( ifstream& file ) {

  // event pointer and identifier
  Event* ev;
  int i;

  // try to read input file
  // on success create new event
  if ( file.read( reinterpret_cast<char*>( &i ),
                                   sizeof(  i ) ) ) ev = new Event( i );
  // on failure return null pointer
  else return nullptr;

  // read number of points
  int n;
  file.read( reinterpret_cast<char*>( &n ), sizeof( n ) );

  // read and store all points
  int e;
  for ( i = 0; i < n; ++i ) {
    file.read( reinterpret_cast<char*>( &e ), sizeof( e ) );
    ev->add( e );
  }

  return ev;

}

