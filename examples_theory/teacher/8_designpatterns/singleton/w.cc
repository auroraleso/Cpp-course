#include "WrongS.h"

#include <iostream>
using namespace std;

void w() {
  cout << "start w" << endl;
  // get the instance of WrongS and call function "get"
  int i = WrongS::instance()->get();
  cout << "got " << i << endl;
  return;
}


