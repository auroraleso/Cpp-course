#include "A.h"
#include "B.h"

#include <iostream>
using namespace std;

void f( const A& a ) {
  a.f();
  return;
}


void g( const B& b ) {
  b.f();
  return;
}


int main() {

  // automatic construction of a temporary object "A" from "int 5",
  f( 5 );

  // automatic construction of a temporary object "B" from "int 6":
  // not working because B(int) constructor is explicit,
//  g( 6 );

  // explicit construction of a temporary object "B" from "int 6":
  g( B( 6 ) );

  return 0;

}

