#ifndef IntermediateA_h
#define IntermediateA_h

#include "Base.h"

class IntermediateA: public Base {

 public:

  IntermediateA( int i );
  ~IntermediateA() override;

 private:

  int k;

};

#endif

