#ifndef Point_h
#define Point_h

class Point {

 public: // accessible by all functions

  Point( float x, float y );
  ~Point();

  float getX() const;
  float getY() const;
  float dist() const;
  float dist( const Point& p ) const;

 private: // accessible only by the class

  const float xp;
  const float yp;
  mutable float dp;

};

#endif
