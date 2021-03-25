#ifndef Vector2D_h
#define Vector2D_h

#include <iostream>

class Vector2D {

 public:

  Vector2D();
  Vector2D( float x, float y );
  ~Vector2D();

  float getX() const;
  float getY() const;
  float mod() const;

  Vector2D operator+( const Vector2D& v ) const;
  Vector2D& operator*=( float f );

 private:

  float xv;
  float yv;

};

#endif
