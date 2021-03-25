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
  cout << "***********" << endl;

  // transform only x and y components
  u.transform( 2.5, 3.5 );
  cout << u.getX() << " " << u.getY() << " " << u.getZ() << endl;

  return 0;

}

