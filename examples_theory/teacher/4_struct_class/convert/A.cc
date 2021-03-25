#include "A.h"

#include <iostream>

A::A( int i ):
 n( i ) {
}


A::~A() {
}


void A::f() const {
  std::cout << "A::f " << n << std::endl;
}

