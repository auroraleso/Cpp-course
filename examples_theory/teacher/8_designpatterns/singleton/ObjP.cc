#include "ObjP.h"

#include <iostream>
using namespace std;

ObjP::ObjP() {
  cout << "create ObjP " << this << endl; 
}


ObjP::~ObjP() {
  cout << "delete ObjP " << this << endl; 
}


// get the object instance
ObjP* ObjP::instance() {
  cout << "ObjP::instance " << endl; 
  // the object is created only once, the first time "instance()" is called
  static ObjP* obj = new ObjP;
  return obj;
}


// object functions
void ObjP::set( int i ) {
  cout << "ObjP::set(" << i << ") " << this << endl;
  c = i;
  return;
}


int ObjP::get() {
  cout << "ObjP::get() " << this << endl;
  return c;
}

