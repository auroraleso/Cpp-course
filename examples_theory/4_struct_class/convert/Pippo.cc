#include "Pippo.h"

#include <iostream>

Pippo::Pippo( int i ):
 n( i ) {
}


Pippo::~Pippo() {
}


Pippo::operator int() const {
  return n;
}


