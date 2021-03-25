#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Area.h"
#include "Perimeter.h"

#include <iostream>
//#include <typeinfo>
#include <vector>
using namespace std;

void func( vector<Shape*>& shape,
           vector<Operation*>& operation );

int main() {

  vector<Shape*> shape;

  cout << "create triangle  with height 3.5 and base 6.7" << endl;
  shape.push_back( new Triangle ( 3.5, 6.7 ) );
  cout << "create triangle  with sides 5.6, 7.5, 4.2" << endl;
  shape.push_back( new Triangle ( 5.6, 7.5, 4.2 ) );
  cout << "create rectangle with height 5.3 and base 7.6" << endl;
  shape.push_back( new Rectangle( 5.3, 7.6 ) );
  cout << "create square    with side   4.4" << endl;
  shape.push_back( new Square   ( 4.4 ) );

  vector<Operation*> operation;

  cout << "create Perimeter" << endl;
  operation.push_back( new Perimeter );
  cout << "create Area" << endl;
  operation.push_back( new Area );

  func( shape, operation );

  return 0;

}


