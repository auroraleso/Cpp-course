#ifndef Square_h
#define Square_h

#include "Shape.h"

class Square: public Shape {

 public:

  Square( float s );
  ~Square() override;

  void exec( Operation& o ) const override;

  float side() const ;

 private:

  float sS;

};

#endif

