#include "ObjS.h"

#include <iostream>
using namespace std;

ObjS::ObjS() {
  cout << "create ObjS " << this << endl; 
}


ObjS::~ObjS() {
  cout << "delete ObjS " << this << endl; 
}


// get the object instance
ObjS* ObjS::instance() {
  cout << "ObjS::instance " << endl; 
  // the object is created only once, the first time "instance()" is called
  static ObjS obj;
  return &obj;
}


// object functions
void ObjS::set( int i ) {
  cout << "ObjS::set(" << i << ") " << this << endl;
  c = i;
  return;
}


int ObjS::get() {
  cout << "ObjS::get() " << this << endl;
  return c;
}

