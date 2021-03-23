#include "Pippo.h"

// The constructor of Pluto uses "cout", and there's no guarantee 
// it's properly set when "p" is instantiated; moreover this can 
// depend, in unpredicible way, on the order of the .cc files in 
// the compilation command.
//#include <iostream>
Pluto p;

Pippo::Pippo() {
}


Pippo::~Pippo() {
}


void Pippo::f() {
  p.f();
  return;
}

