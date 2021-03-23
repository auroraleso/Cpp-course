#include "Shape.h"

#include <iostream>
using namespace std;

Shape::Shape() {
  cout << "create Shape" << endl;
  // in the constructor the derived classes functions cannot be called
  // neither directly nor indirectly: zero will be printed for 
  // area and perimeter
  print();
}


Shape::~Shape() {
  cout << "delete Shape" << endl;
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
// functions for actual object (triangle, square...) are called,
// unless the function is called by Shape constructor or destructor
void Shape::print() const {
  cout << "perimeter " << perimeter()
       << " and area " << area() << endl;
  return;
}

