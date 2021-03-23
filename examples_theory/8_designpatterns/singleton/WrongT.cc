#include "WrongT.h"
#include "WrongS.h"

#include <iostream>
using namespace std;

WrongT wt;

WrongT::WrongT() {
  cout << "WrongT::WrongT" << endl;
  singPtr = WrongS::instance();
  cout << "singPtr " << singPtr << endl;
}


WrongT::~WrongT() {
}


void WrongT::f() {
  cout << "WrongT::f()" << endl;
  cout << singPtr->get() << endl;
  return;
}

