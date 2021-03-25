#include "ObjT.h"

#include <iostream>
using namespace std;

ObjT::ObjT() {
  cout << "create ObjT " << this << endl; 
}


ObjT::~ObjT() {
  cout << "delete ObjT " << this << endl; 
}


void ObjT::set( int i ) {
  cout << "ObjT::set(" << i << ") " << this << endl;
  c = i;
  return;
}


int ObjT::get() {
  cout << "ObjT::get() " << this << endl;
  return c;
}

