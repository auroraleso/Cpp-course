#include "A.h"
#include <iostream>
using namespace std;

A::A() {
  n = 0;
}


A::~A() {
}


void A::f() const {
  cout << n++ << endl;
}

