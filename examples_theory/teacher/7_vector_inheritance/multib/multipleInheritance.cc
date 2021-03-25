#include "BaseA.h"
#include "BaseB.h"
#include "Derived.h"
#include <iostream>
using namespace std;

int main() {

  BaseA* a = new BaseA;
  BaseB* b = new BaseB;
  Derived* d = new Derived;

  // calls to functions for base objects are not ambiguous
  a->g();
  b->g();
  // calls to g for derived object are not ambiguous, 
  // as derived objects reimplement the function
  d->g();

  cout << " ********* " << endl;

  // calls to f for derived object are ambiguous, 
  // as functions f(...) exist in both bases,
  // even if they have different parameters
  // calling them without disambiguating leads to a compilation error
//  d->f( 2 );
//  d->f();
  d->BaseA::f( 2 );
  d->BaseB::f();

  cout << " ********* " << endl;

  // a the pointer to a an object derived from multiple bases can change
  // when copied onto a pointer to a base class,
  // as the base objects contained in the derived one are stored 
  // in different memory locations
  a = d;
  b = d;
  cout << "a=d: " << a << " " << d << endl;
  cout << "b=d: " << b << " " << d << endl;
  cout << "a->g() : ";
  a->g();
  cout << "b->g() : ";
  b->g();

  return 0;

}

