#ifndef Point_h
#define Point_h

class Line;

class Point {

 public: // accessible by all functions

  Point( float x, float y );
  ~Point();

  float getX() const;
  float getY() const;
  float dist( const Point& p ) const;
  float dist( const Line & l ) const;

 private: // accessible only by the class

  float xp;
  float yp;

};

#endif
