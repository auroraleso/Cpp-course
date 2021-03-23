#include "Reader.h"

#include <string>

using namespace std;

int main( int argc, char* argv[] ) {

  const string name = argv[1];
  const string mode = argv[2];

  Reader& op = *ReaderFactory::create( name, ( mode == "b" ?
                                               ios::binary :
                                               ios::out ) );

  int   a;
  float b;
  bool  c;
  op >> a >> b >> c;
  cout << "a = " << a << endl
       << "b = " << b << endl
       << "c = " << c << endl;

  delete &op;

  return 0;
  
}


