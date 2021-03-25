#include <iostream>
#include <cmath>

//struct Point;
//struct Point;
//struct Point;
struct Point {
  float x;
  float y;
};

float mod( const Point* p ) {
  return sqrt( pow( p->x, 2 ) + pow( p->y, 2 ) );
}

float dist( const Point& p1, const Point& p2 ) {
  return sqrt( pow( p1.x - p2.x, 2 ) + pow( p1.y - p2.y, 2 ) );
}

int main() {

  Point p1;
  p1.x = 2.3; // single member assignment
  p1.y = 4.5;

  Point p2 { 6.1, 1.8 }; // structure initialization

  std::cout << mod( &p1 ) << std::endl;
  std::cout << mod( &p2 ) << std::endl;
  std::cout << dist( p1, p2 ) << std::endl;

  return 0;

}

