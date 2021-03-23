#include "WrongS.h"

#include <iostream>
using namespace std;

WrongS* WrongS::obj = nullptr;

WrongS::WrongS() {
  cout << "create WrongS " << this << endl; 
}


WrongS::~WrongS() {
  cout << "delete WrongS " << this << endl; 
}


// get the object instance
WrongS* WrongS::instance() {
  cout << "WrongS::instance " << endl; 
  // the object is created only once, the first time "instance()" is called
  if ( obj == nullptr ) obj = new WrongS;
  return obj;
}


// object functions
void WrongS::set( int i ) {
  cout << "WrongS::set(" << i << ") " << this << endl;
  c = i;
  return;
}


int WrongS::get() {
  cout << "WrongS::get() " << this << endl;
  return c;
}

