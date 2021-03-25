#ifndef IntermediateA_h
#define IntermediateA_h

#include "Base.h"

// IntermediateA shares its base with other classes in the same
// inheritance chain
class IntermediateA: public virtual Base {

 public:

  IntermediateA( int i );
  ~IntermediateA() override;
  void toBeRedefined() override;

 private:

  int k;

};

#endif

