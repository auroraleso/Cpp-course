#include "MathException.h"

#include <iostream>
using namespace std;

float div( float x, int i ) {
  cout << "start div" << endl;
  if ( i == 0 ) throw MathException( MathException::divByZero );
  float z = x / i;
  cout << "end div" << endl;
  return z;
}

float f( float x ) noexcept {
  cout << "start f" << endl;
  int i;
  cin >> i;
  float z = div( x, i );
  cout << "end f" << endl;
  return z;
}

float g() {
  cout << "start g" << endl;
  float x = 5.3;
  float z = f( x );
  cout << "end g" << endl;
  return z;
}

int main() {
  try {
    cout << "call g" << endl;
    float y = g();
    cout << "done g" << endl;
    cout << y << endl;
  }
  catch ( MathException& e ) {
    cout <<  e.message() << endl;
  }
  return 0;
}

