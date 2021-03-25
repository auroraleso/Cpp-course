#include "ObjT.h"

#include <iostream>
using namespace std;

void t();

int main() {

  // activate print of all operations
  ObjT::verbose = true;

  cout << "start main" << endl;

  // get the instance of ObjT and call function "set"
  ObjT::instance()->set( 765 );

  cout << "call t()" << endl;
  t();

  return 0;

}


