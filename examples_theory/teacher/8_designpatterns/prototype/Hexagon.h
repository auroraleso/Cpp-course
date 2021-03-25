#ifndef Hexagon_h
#define Hexagon_h

#include "Shape.h"

// a Hexagon is a Shape
class Hexagon: public Shape {

 public:

  Hexagon( float s );
  ~Hexagon() override;

  // specific function for squares: get side
  float side() const;

  // redeclaration of functions to compute are and perimeter
  // to perform specific calculations for squares
  float area()      const override;
  float perimeter() const override;

  // create a new Hexagon with dimensions as described in "info"
  Shape* clone( const std::string& info ) const override;

 private:

  // specific data for squares: side
  float hS;

};

#endif

