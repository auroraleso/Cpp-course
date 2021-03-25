#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle: public Shape {

 public:

  Rectangle( float b, float h );
  ~Rectangle() override;

  void exec( Operation& o ) const override;

  float base() const ;
  float height() const ;

 private:

  float rB;
  float rH;

};

#endif

