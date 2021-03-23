#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"

// a Triangle is a Shape
class Triangle: public Shape {

 public:

  // create with base b and height h
  Triangle( float b, float h );
  // create with 3 sides
  Triangle( float a, float b, float c );
  ~Triangle() override;

  // execute operation
  void exec( Operation& o ) const override;

  // specific functions for triangles: get base and height
  float base() const ;
  float height() const ;
  float width() const ;

 private:

  // specific data for triangles: sides
  float sA;
  float sB;
  float sC;

};

#endif

