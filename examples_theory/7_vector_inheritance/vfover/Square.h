#ifndef Square_h
#define Square_h

#include "Shape.h"

// a Square is a Shape
class Square: public Shape {

 public:

  // create with side s
  Square( float s );
  ~Square() override;

  // specific function for squares: get side
  float side() const;

  // redeclaration of functions to compute are and perimeter
  // to perform specific calculations for squares
  float area()      const override;
  float perimeter() const override;

 private:

  // specific data for squares: side
  float sS;

};

#endif

