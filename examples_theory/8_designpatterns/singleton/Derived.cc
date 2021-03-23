#include "Derived.h"
#include <iostream>
using namespace std;


Derived::Derived() {
  cout << "create Derived" << endl;
}


Derived::~Derived() {
}


void Derived::f() {
  cout << "Derived::f()" << endl;
  return;
}

static Derived d;
