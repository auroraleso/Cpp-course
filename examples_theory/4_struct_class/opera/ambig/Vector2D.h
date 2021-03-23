#ifndef Vector2D_h
#define Vector2D_h

class Vector2D;
Vector2D& operator*=( Vector2D& v, float f );
Vector2D operator*( float f, Vector2D& v );
Vector2D operator+( const Vector2D& vl, const Vector2D& vr );

class Vector2D {

 public:

  Vector2D();
  Vector2D(float x, float y);
  ~Vector2D();

  float getX() const;
  float getY() const;
  float mod() const;

  Vector2D operator+( const Vector2D& v ) const;
  Vector2D& operator*=( float f );
  Vector2D  operator* ( float f ) { return f * *this; }

 private:

  float xv;
  float yv;

};

#endif
