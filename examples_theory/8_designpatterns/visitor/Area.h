#ifndef Area_h
#define Area_h

#include "Operation.h"

class Area: public Operation {

 public:

  Area();
  ~Area() override;

  void exec( const Triangle & t ) override;
  void exec( const Square   & s ) override;
  void exec( const Rectangle& r ) override;

  float get() override;

 private:

  float shapeA;

};

#endif

