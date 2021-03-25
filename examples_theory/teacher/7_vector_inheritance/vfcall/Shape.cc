#include "Shape.h"

#include <iostream>
using namespace std;

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


// print area and perimeter:
// functions for actual object (triangle, square...) are called
void Shape::print() const {
  cout << "perimeter " << perimeter()
       << " and area " << area() << endl;
  return;
}

