#include "Shape.h"

#include <iostream>
using namespace std;

Shape::Shape( const string& name ): m_name( name ) {
}


Shape::~Shape() {
//  print();
}


const std::string& Shape::name() const {
  return m_name;
}

// print area and perimeter:
// functions for actual object (triangle, square...) are called,
// unless the function is called by Shape constructor or destructor
void Shape::print() const {
  cout << name()      << " has perimeter "
       << perimeter() << " and area "
       << area()      << endl;
  return;
}

