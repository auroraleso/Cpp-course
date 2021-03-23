#include "Vector2D.h"
#include <cmath>

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

Vector2D Vector2D::operator+( const Vector2D& v ) const {
  return Vector2D( xv + v.xv, yv + v.yv );
}

Vector2D& Vector2D::operator*=( float f ) {
  xv *= f;
  yv *= f;
  return *this;
}

