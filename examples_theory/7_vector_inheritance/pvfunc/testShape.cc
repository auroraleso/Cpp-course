#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {

  // an array of geometric shapes
  vector<Shape*> shape;

  // a generic Shape cannot be created, an attempt to create one
  // leads to a compilation error
//  cout << "create generic shape" << endl;
//  shape.push_back( new Shape );
  cout << "create triangle  with base 3.5 and height 6.7" << endl;
  shape.push_back( new Triangle ( 3.5, 6.7 ) );
  cout << "create triangle  with sides 5.6, 7.5, 4.2" << endl;
  shape.push_back( new Triangle ( 5.6, 7.5, 4.2 ) );
  cout << "create rectangle with base 5.3 and height 7.6" << endl;
  shape.push_back( new Rectangle( 5.3, 7.6 ) );
  cout << "create square    with side 4.4" << endl;
  shape.push_back( new Square   ( 4.4 ) );

  cout << "************" << endl;

  // loop over shapes
  int i;
  int n = shape.size();
  for ( i = 0; i < n; ++i ) {
    // get the pointer to the shape
    const Shape* s = shape[i];
    // print area and perimeter: each shape is handled
    // according to its actual type (triangle, square...)
    cout << "shape " << i
         << " has perimeter " << s->perimeter()
         << " and area "      << s->area() << endl
         << "----------"      << endl;
    // print area and perimeter: the print functions handles the shape 
    // according to its actual type (triangle, square...) despite
    // it's defined only in the base class
    s->print();
    cout << "++++++++++"      << endl;
  }

  // delete all the shapes
  for ( i = 0; i < n; ++i ) delete shape[i];

  return 0;

}


