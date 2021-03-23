#include "ObjS.h"

#include <iostream>
using namespace std;

void g() {
  cout << "start g" << endl;
  // get the instance of ObjS and call function "get"
  int i = ObjS::instance()->get();
  cout << "got " << i << endl;
  return;
}


