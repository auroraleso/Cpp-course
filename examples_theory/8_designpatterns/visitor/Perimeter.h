#ifndef Perimeter_h
#define Perimeter_h

#include "Operation.h"

class Perimeter: public Operation {

 public:

  Perimeter();
  ~Perimeter() override;

  void exec( const Triangle & t ) override;
  void exec( const Square   & s ) override;
  void exec( const Rectangle& r ) override;

  float get() override;

 private:

  float shapeP;

};

#endif

