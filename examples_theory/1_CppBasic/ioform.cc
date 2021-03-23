
// read a floating point number and write it with different formats

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

  float x;
  std::cin >> x;
  std::cout << "123456789012345678901234567890" << std::endl;
  std::cout << "***";
  std::cout.width( 12 );
  std::cout.precision( 5 );
  std::cout << x;
  std::cout << "***" << std::endl;
  std::cout << "***" << x << "***" << std::endl;
  std::cout << "***" << std::setw( 12 ) << std::setprecision( 5 )
            << sqrt( x ) << "***" << std::endl;
  std::cout << "***" << sqrt( x ) << "***" << std::endl;

  return 0;

}
