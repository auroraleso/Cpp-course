#include "IntMultiplier.h"
#include "CheckPrime.h"
#include <iostream>

IntMultiplier::IntMultiplier( const std::string& n ): name( n ) {}

IntMultiplier::~IntMultiplier() {
}

void IntMultiplier::update( const int& x ) {

  // print the received number
  std::cout << name << " got " << x << std::endl;
  // multiply the number by the ASCII code of the first character of the name
  result = x * *name.c_str();

  // check if number is prime
  CheckPrime* cp = CheckPrime::instance();
  bool notPrime = !cp->isPrime();
  // print number being prime or not
  std::cout << name << " checked " << x << " is";
  if ( notPrime ) std::cout << " not";
  std::cout << " prime" << std::endl;

  return;

}

int IntMultiplier::get() {
  check();
  return result;
}


