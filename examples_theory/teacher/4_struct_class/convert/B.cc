#include "B.h"

#include <iostream>

B::B( int i ):
 n( i ) {
}


B::~B() {
}


void B::f() const {
  std::cout << "B::f " << n << std::endl;
}

