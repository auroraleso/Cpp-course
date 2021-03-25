
// write two function with the same name "dist", taking 4 or 6 arguments
// and computing the distance between 2 point in 2D or 3D

#include <iostream>
#include <cmath>

float dist( float x1, float y1,
            float x2, float y2 ) {
  return sqrt( pow( x1 - x2, 2 ) +
               pow( y1 - y2, 2 ) );
}

float dist( float x1, float y1, float z1,
            float x2, float y2, float z2 ) {
  return sqrt( pow( x1 - x2, 2 ) +
               pow( y1 - y2, 2 ) +
               pow( z1 - z2, 2 ) );
}

int main() {

  float x1 = 1.23;
  float y1 = 2.34;
  float z1 = 3.45;
  float x2 = 3.21;
  float y2 = 2.13;
  float z2 = 1.32;
  std::cout << dist( x1, y1,     x2, y2     ) << std::endl;
  std::cout << dist( x1, y1, z1, x2, y2, z2 ) << std::endl;
  return 0;

}
