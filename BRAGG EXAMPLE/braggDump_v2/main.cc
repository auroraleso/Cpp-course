#include <iostream>
#include <fstream>

// a "forward declaration" is sufficient,
// only a pointer to Event is used in the following
struct Event;

const Event* read( std::ifstream& file );
void dump( const Event& ev );
void clear( const Event* ev );

int main( int argc, char* argv[] ) {

  // open input file
  const char* name = argv[1];
  std::ifstream file( name, std::ios::binary );

  // loop over events
  const Event* ev;
  while ( ( ev = read( file ) ) != nullptr ) {
    dump( *ev );
    clear( ev );
  }

  return 0;

}

