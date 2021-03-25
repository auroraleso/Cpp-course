#include "Shape.h"

#include <iostream>
using namespace std;

Shape::Shape() {
  // perimeter and area are "pure virtual functions":
  // calling them in the constructor or destructor leads
  // to a compilation error
//  cout << "perimeter " << perimeter()
//       << " and area " << area() << endl;
  // print is not a "pure virtual functions" and the compiler 
  // allows calling it in the constructor or destructor, 
  // print in its turn calls area and perimeter functions, leading
  // to a "pure virtual method called" error at runtime
//  print();
}


Shape::~Shape() {
//  print();
}


// print area and perimeter:
// functions for actual object (triangle, square...) are called,
// unless the function is called by Shape constructor or destructor
void Shape::print() const {
  cout << "perimeter " << perimeter()
       << " and area " << area() << endl;
  return;
}

