#ifndef Derived_h
#define Derived_h

#include "Base.h"

class Derived: public Base {

 public:

  Derived();
  ~Derived() override;

  void f() override;

 private:

  Derived           ( const Derived& x ) = delete;
  Derived& operator=( const Derived& x ) = delete;

};

#endif

