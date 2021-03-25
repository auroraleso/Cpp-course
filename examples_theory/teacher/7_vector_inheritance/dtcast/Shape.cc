#include "Shape.h"

#include <iostream>
using namespace std;

Shape::Shape() {
}


Shape::~Shape() {
}


// print area and perimeter:
// functions for actual object (triangle, square...) are called,
// unless the function is called by Shape constructor or destructor
void Shape::print() const {
  cout << "perimeter " << perimeter()
       << " and area " << area() << endl;
  return;
}

