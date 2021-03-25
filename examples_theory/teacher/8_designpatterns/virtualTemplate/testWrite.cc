#include "Writer.h"

#include <string>

using namespace std;

int main( int argc, char* argv[] ) {

  const string name = argv[1];
  const string mode = argv[2];

  Writer& op = *WriterFactory::create( name, ( mode == "b" ?
                                               ios::binary :
                                               ios::out ) );

  int   a = 12;
  float b = 34.56;
  bool  c = true;
  op << Writer::Cleaner( "a = " ) << a << Writer::Cleaner( endl )
     << Writer::Cleaner( "b = " ) << b << Writer::Cleaner( endl )
     << Writer::Cleaner( "c = " ) << c << Writer::Cleaner( endl );

  delete &op;

  return 0;
  
}


