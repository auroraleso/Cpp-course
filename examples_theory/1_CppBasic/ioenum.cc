
// define enums and write them

#include <iostream>

int main() {

  enum Name { aldo, giovanni, giacomo };
  enum Polygon { triangle = 3, square, pentagon, hexagon };
  enum Color { red    = 11, green, blue  , 
               yellow = 21, cyan , purple };

  std::cout << "Names: " << std::endl;
  std::cout << "aldo     : " << aldo     << std::endl;
  std::cout << "giovanni : " << giovanni << std::endl;
  std::cout << "giacomo  : " << giacomo  << std::endl;
  std::cout << std::endl;

  std::cout << "Polygons: " << std::endl;
  std::cout << "triangle      : " << triangle      << std::endl;
  std::cout << "square        : " << square        << std::endl;
  std::cout << "pentagon      : " << pentagon      << std::endl;
  std::cout << "hexagon       : " << hexagon       << std::endl;
  std::cout << std::endl;

  std::cout << "Colors: " << std::endl;
  std::cout << "red    : " << red    << std::endl;
  std::cout << "green  : " << green  << std::endl;
  std::cout << "blue   : " << blue   << std::endl;
  std::cout << "yellow : " << yellow << std::endl;
  std::cout << "cyan   : " << cyan   << std::endl;
  std::cout << "purple : " << purple << std::endl;

  return 0;

}
