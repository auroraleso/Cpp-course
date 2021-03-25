#include "Vector3D.h"
#include <cmath>

// The Vector2D part is initialized by default
Vector3D::Vector3D():
 zv( 0.0 ) {
}

// The Vector2D part is explicitly initialized with x, y
Vector3D::Vector3D( float x, float y, float z ):
 Vector2D( x, y ),
 zv( z ) {
}

Vector3D::~Vector3D() {
}

float Vector3D::getZ() const {
  return zv;
}

// reimplement modulus calculation
float Vector3D::mod() const {
  // xv and yv cannot be accessed directly, as they're private
  return sqrt( ( getX() * getX() ) + ( getY() * getY() ) + ( zv * zv ) );
}

