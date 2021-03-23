#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

// a Rectangle is a Shape
class Rectangle: public Shape {

 public:

  // create with base b and height h
  Rectangle( float b, float h );
  ~Rectangle() override;

  // specific functions for rectangles: get base and height
  float base() const;
  float height() const;

  // redeclaration of functions to compute are and perimeter
  // to perform specific calculations for rectangles
  float area()      const override;
  float perimeter() const override;

 private:

  // specific data for rectangles: base and height
  float rB;
  float rH;

};

#endif

