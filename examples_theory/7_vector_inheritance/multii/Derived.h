#ifndef Derived_h
#define Derived_h

#include "IntermediateA.h"
#include "IntermediateB.h"

// Derived class inherits from IntermediateA and IntermediateB
// which in turn inherit from Base, so that Derived contains two Base objects
class Derived: public IntermediateA, public IntermediateB {

 public:

  Derived( int i, int j );
  ~Derived() override;

};

#endif

