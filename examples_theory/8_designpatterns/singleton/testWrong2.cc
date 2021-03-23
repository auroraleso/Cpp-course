#include "WrongS.h"
#include "WrongT.h"

#include <iostream>
using namespace std;

extern WrongT wt;

int main() {

  cout << "start main" << endl;

  // get the instance of WrongS and call function "set"
  WrongS::instance()->set( 321 );
  cout << "call wt.f()" << endl;
  wt.f();

  return 0;

}


