#ifndef Line_h
#define Line_h

class Point;

class Line {

 public:

  Line( const Point& p1, const Point& p2 );
  ~Line();

  Point intersect( const Line& l ) const;
  float dist( const Point& p ) const;

 private:

  static float tolerance;
  float a;
  float b;
  float c;

};

#endif
