#ifndef IntermediateB_h
#define IntermediateB_h

#include "Base.h"

// IntermediateB shares its base with other classes in the same
// inheritance chain
class IntermediateB: public virtual Base {

 public:

  IntermediateB( int i );
  ~IntermediateB() override;

  // a redeclaration of this function, redeclared by IntermediateA too,
  // requires a redeclaration and redefinition in Derived,
  // to disambiguate calls
//  virtual void toBeRedefined();

  void checkWhere();

 private:

  int k;

};

#endif

