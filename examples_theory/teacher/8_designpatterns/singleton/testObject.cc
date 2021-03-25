#include "ObjS.h"

#include <iostream>
using namespace std;

void g();

int main() {

  cout << "start main" << endl;

  // get the instance of ObjS and call function "set"
  ObjS::instance()->set( 321 );

  cout << "call g()" << endl;
  g();

  cout << "end main" << endl;
  return 0;

}


