#include "Vector2D.h"

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

Vector2D Vector2D::operator+( const Vector2D& v ) const {
  return Vector2D( xv + v.xv, yv + v.yv );
}

Vector2D& Vector2D::operator*=( float f ) {
  xv *= f;
  yv *= f;
  return *this;
}

