#include "Base.h"
#include <iostream>
using namespace std;


Base::Base() {
  Base*& i = instRef();
  if ( i == nullptr ) i = this;
}


Base::~Base() {
}


Base* Base::instance() {
  if ( instRef() == nullptr ) new Base;
  return instRef();
}


Base*& Base::instRef() {
  static Base* obj = nullptr;
  return obj;
}


void Base::f() {
  cout << "Base::f()" << endl;
  return;
}

