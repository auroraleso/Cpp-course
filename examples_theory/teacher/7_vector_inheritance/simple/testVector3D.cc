#include "Vector3D.h"

#include <iostream>

using namespace std;

int main() {

  // create two Vector3D objects
  Vector3D u(  3.4, 4.5, 7.2 );
  Vector3D v( -1.6, 6.9, 2.8 );

  // print components: Vector2D functions can be used directly
  cout << u.getX() << " " << u.getY() << " " << u.getZ() << endl;
  cout << v.getX() << " " << v.getY() << " " << v.getZ() << endl;

  // add the two vectors: Vector3D objects can be used in place
  // of Vector2D objects
  Vector2D s = u + v;
  cout << s.getX() << " " << s.getY() << endl;

  return 0;

}

