#include "IntPower.h"
#include <iostream>
#include <cmath>

IntPower::IntPower( int p ): power( p ) {
}

IntPower::~IntPower() {
}

void IntPower::update( const int& x ) {
  std::cout << x << "^" << power << " = " << pow( x, power ) << std::endl;
  return;
}

