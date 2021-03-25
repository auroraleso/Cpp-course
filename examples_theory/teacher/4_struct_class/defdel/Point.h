#ifndef Point_h
#define Point_h

class Point {

 public: // accessible by all functions

  Point() = default;
  Point( float d );
  Point( float x, float y );
  ~Point();

  float getX() const;
  float getY() const;
  float dist( const Point& p ) const;

 private: // accessible only by the class

  float xp = 0.0;
  float yp = 0.0;

};

#endif
