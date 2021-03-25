#include "ObjP.h"

#include <iostream>
using namespace std;

void h();

int main() {

  cout << "start main" << endl;

  // get the instance of ObjP and call function "set"
  ObjP::instance()->set( 321 );

  cout << "call h()" << endl;
  h();

  cout << "end main" << endl;
  return 0;

}


