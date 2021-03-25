#include "ObjT.h"

#include <iostream>
using namespace std;

void t() {
  cout << "start t" << endl;
  // get the instance of ObjT and call function "get"
  int i = ObjT::instance()->get();
  cout << "got " << i << endl;
  return;
}


