#include "CheckPrime.h"
#include <iostream>
#include <cmath>

CheckPrime* CheckPrime::instance() {
  static CheckPrime* ckPrime = new CheckPrime();
  return ckPrime;
}

CheckPrime::CheckPrime() {
  std::cout << "create CheckPrime" << std::endl;
}

CheckPrime::~CheckPrime() {
}

void CheckPrime::update( const int& x ) {
  std::cout << "check prime: " << x << std::endl;
  primeFlag = true;
  int i = 2;
  while ( ( i <= sqrt( x ) ) && ( primeFlag &= ( ( x % i ) != 0 ) ) ) ++i;
  return;
}

bool CheckPrime::isPrime() {
  check();
  return primeFlag;
}


