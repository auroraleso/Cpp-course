#include "Shape.h"


Shape::Shape() {
}


Shape::~Shape() {
}

// area undefined for generic shape: return zero
float Shape::area() const {
  return 0.0;
}

// perimeter undefined for generic shape: return zero
float Shape::perimeter() const {
  return 0.0;
}

