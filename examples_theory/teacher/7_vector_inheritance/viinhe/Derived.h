#ifndef Derived_h
#define Derived_h

#include "IntermediateA.h"
#include "IntermediateB.h"

// Derived class inherits from IntermediateA and IntermediateB
// which in turn inherit from Base; it contains only one Base object
// as Base is a virtual base for both IntermediateA and IntermediateB
class Derived: public IntermediateA, public IntermediateB {

 public:

  Derived( int i, int j );
  ~Derived() override;

  // a redeclaration of this function is needed to disambiguate calls
  // if it's redefined both by IntermediateA and IntermediateB
//  virtual void toBeRedefined();

};

#endif

