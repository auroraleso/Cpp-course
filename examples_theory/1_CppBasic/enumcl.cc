
// C++11 code
// define enum classes and write them

#include <iostream>

enum class Name { aldo, giovanni, giacomo };
enum class Polygon: char { triangle = 3, square, pentagon, hexagon };
enum class Color: int { red    = 11, green, blue  , 
                        yellow = 21, cyan , purple };

/*
-----------------------------ENUM SIZEOF-------------------------------------
    An enum is only guaranteed to be large enough to hold int values. 
    The compiler is free to choose the actual type used based on the
    enumeration constants defined so it can choose a smaller type if it can 
    represent the values you define. If you need enumeration constants that 
    don't fit into an int you will need to use compiler-specific extensions 
    to do so.
*/

void print ( const Name& x ) {
  std::cout << sizeof( x ) << " " << static_cast<int>( x ) << " ";
  switch ( x ) {
  case Name::aldo:
    std::cout << "aldo"      << std::endl;
    break;
  case Name::giovanni:
    std::cout << "giovanni"  << std::endl;
    break;
  case Name::giacomo:
    std::cout << "giacomo"   << std::endl;
    break;
  }
  return;
}

void print ( const Polygon& x ) {
  std::cout << sizeof( x ) << " " << static_cast<int>( x ) << " ";
  switch ( x ) {
  case Polygon::triangle:
    std::cout << "triangle"       << std::endl;
    break;
  case Polygon::square:
    std::cout << "square"  << std::endl;
    break;
  case Polygon::pentagon:
    std::cout << "pentagon"       << std::endl;
    break;
  case Polygon::hexagon:
    std::cout << "hexagon"        << std::endl;
    break;
  }
  return;
}

void print ( const Color& x ) {
  std::cout << sizeof( x ) << " " << static_cast<int>( x ) << " ";
  switch ( x ) {
  case Color::red:
    std::cout << "red"     << std::endl;
    break;
  case Color::green:
    std::cout << "green"  << std::endl;
    break;
  case Color::blue:
    std::cout << "blue"    << std::endl;
    break;
  case Color::yellow:
    std::cout << "yellow"  << std::endl;
    break;
  case Color::cyan:
    std::cout << "cyan"    << std::endl;
    break;
  case Color::purple:
    std::cout << "purple"  << std::endl;
    break;
  }
  return;
}

int main() {

  std::cout << "Names: " << std::endl;
  print( Name::aldo );
  print( Name::giovanni );
  print( Name::giacomo );
  std::cout << std::endl;

  std::cout << "Polygons: " << std::endl;
  print( Polygon::triangle );
  print( Polygon::square );
  print( Polygon::pentagon );
  print( Polygon::hexagon );
  std::cout << std::endl;

  std::cout << "Colors: " << std::endl;
  print( Color::red );
  print( Color::green );
  print( Color::blue );
  print( Color::yellow );
  print( Color::cyan );
  print( Color::purple );

  return 0;

}
