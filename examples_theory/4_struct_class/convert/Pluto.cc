#include "Pluto.h"

#include <iostream>

Pluto::Pluto( int i ):
 n( i ) {
}


Pluto::~Pluto() {
}


Pluto::operator int() const {
  return n;
}


