#include "Vector2D.h"

#include <iostream>
#include <fstream>

int main() {

  Vector2D u;
  Vector2D v;

  std::ifstream file( "vectors.txt" );
  file >> u >> v;
  std::cout << "u = " << u << std::endl;
  std::cout << "v = " << v << std::endl;

  return 0;

}

