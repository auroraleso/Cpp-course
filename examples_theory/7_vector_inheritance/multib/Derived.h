#ifndef Derived_h
#define Derived_h

#include "BaseA.h"
#include "BaseB.h"

class Derived: public BaseA, public BaseB {

 public:

  Derived();
  ~Derived() override;

  // functions f( int i ) and f() are taken
  // from BaseA and BaseB respectively
  // function g() is redeclared
  void g() override;

 private:

  int k;

};

#endif

