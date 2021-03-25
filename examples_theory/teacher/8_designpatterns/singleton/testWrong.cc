#include "WrongS.h"

#include <iostream>
using namespace std;

void w();

int main() {

  cout << "start main" << endl;

  // get the instance of WrongS and call function "set"
  WrongS::instance()->set( 321 );

  cout << "call w()" << endl;
  w();

  return 0;

}


