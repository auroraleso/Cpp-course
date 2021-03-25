#include "ObjP.h"

#include <iostream>
using namespace std;

void h() {
  cout << "start t" << endl;
  // get the instance of ObjP and call function "get"
  int i = ObjP::instance()->get();
  cout << "got " << i << endl;
  return;
}


