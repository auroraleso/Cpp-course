
// write a function that
//  accepts an int
//  multiply it by 2
//  write the result onto the screen

// write a similar function returning the number multiplied by 3

#include <iostream>
#include <cmath>

void int_fun( int i ) {
  i *= 2;
  std::cout << "int fun " << i << std::endl;
  return;
}

int ret_fun( int i ) {
//  std::cout << "ret fun " << i << std::endl;
  return (i*3);
}

int main() {

  int j;
  std::cin >> j;
  int_fun( j );
  std::cout << j << std::endl;
  std::cout << "==============" << std::endl;
  std::cout << ret_fun( j ) << std::endl;
  std::cout << "==============" << std::endl;
  return 0;

}
