#include "Vector2D.h"
#include <cmath>

#include <iostream>

/*
*/
Vector2D& operator*=( Vector2D& v, float f ) {
  std::cout << "::*=" << std::endl;
  v = Vector2D( v.getX() * f, v.getY() * f );
  return v;
}

Vector2D operator+( const Vector2D& vl, const Vector2D& vr ) {
  std::cout << "::+" << std::endl;
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

/*
*/
Vector2D Vector2D::operator+( const Vector2D& v ) const {
  std::cout << "Vector2D::+" << std::endl;
  return Vector2D( xv + v.xv, yv + v.yv );
}

Vector2D& Vector2D::operator*=( float f ) {
  std::cout << "Vector2D::*=" << std::endl;
  xv *= f;
  yv *= f;
  return *this;
}

