#include "IntObserver.h"
#include <iostream>

IntObserver::IntObserver( const std::string& n ): name( n ) {
}

IntObserver::~IntObserver() {
}

void IntObserver::update( const int& x ) {
  std::cout << name << " got " << x << std::endl;
  return;
}

