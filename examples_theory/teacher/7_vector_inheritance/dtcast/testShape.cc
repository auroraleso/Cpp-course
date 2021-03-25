#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

#include <iostream>
// required to use the "typeid" function
//#include <typeinfo>
#include <vector>
using namespace std;

int main() {

  // an array of geometric shapes
  vector<Shape*> shape;

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
    // try to force the pointer to be a pointer to a square
    // if the shape is not a square a null pointer will be obtained
    const Square* q = dynamic_cast<const Square*>( s );
    // if the pointer is not null the shape is a square and
    // its side can be obtained
    if ( q != nullptr ) cout << "square side: " << q->side() << endl;
    else                cout << "not a square" << endl;
    // test the actual type of the shape via the typeid function
//    if ( typeid( *s ) == typeid( Square ) )
//                  cout << "square side: "
//                       << dynamic_cast<const Square*>( s )->side() << endl;
//    else          cout << "not a square" << endl;
    cout << "----------"      << endl;
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


