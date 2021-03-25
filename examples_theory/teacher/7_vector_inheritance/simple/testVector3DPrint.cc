#include "Vector3D.h"

#include <iostream>

using namespace std;

// function taking a Vector2D argument by value: objects are copied
// Vector3D objects are copied to Vector2D objects, z component is neglected
void print( const Vector2D v ) {
  // Vector2D modulus is computed and printed
  cout << "mod = " << v.mod() << endl;
  return;
}

int main() {

  // create two Vector3D objects
  Vector3D u(  3.4, 4.5, 7.2 );
  Vector3D v( -1.6, 6.9, 2.8 );

  // print components: Vector2D functions can be used directly
  cout << u.getX() << " " << u.getY() << " " << u.getZ() << endl;
  cout << v.getX() << " " << v.getY() << " " << v.getZ() << endl;

  cout << "****" << endl;

  // print modulus of both objects
  cout << u.mod() << endl;
  cout << v.mod() << endl;

  cout << "****" << endl;

  // call the "print" function with Vector3D objects as arguments
  print( u );
  print( v );

  return 0;

}

