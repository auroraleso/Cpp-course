#include "Vector2D.h"
#include <cmath>

Vector2D& operator*=( Vector2D& v, float f ) {
  v = Vector2D( v.getX() * f, v.getY() * f );
  return v;
}

Vector2D operator+( const Vector2D& vl, const Vector2D& vr ) {
  return Vector2D( vl.getX() + vr.getX(), vl.getY() + vr.getY() );
}

Vector2D::Vector2D():
 xv( 0.0 ),
 yv( 0.0 ) {
}

Vector2D::Vector2D( float x, float y ):
 xv( x ),
 yv( y ) {
}

Vector2D::~Vector2D() {
}

float Vector2D::getX() const {
  return xv;
}

float Vector2D::getY() const {
  return yv;
}

float Vector2D::mod() const {
  return sqrt( ( xv * xv ) + ( yv * yv ) );
}

