#include "Derived.h"
#include <iostream>
using namespace std;

Derived::Derived() {
}

Derived::~Derived() {
}

void Derived::g() {
  // a the pointer to a an object derived from multiple bases can change
  // when copied onto a pointer to a base class,
  // as the base objects contained in the derived one are stored 
  // in different memory locations
  BaseA* a = this;
  BaseB* b = this;
  cout << "Derived::g " << this << " "
       << " - BaseA: " << a << " - Base B: " << b << endl;
}

