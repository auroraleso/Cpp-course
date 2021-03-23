
// write a function that
//  accepts an int "by reference"
//  multiply it by 2
//  write the result onto the screen

// write a similar function accepting the number pointer

#include <iostream>

void ref_fun( int& i ) {
  i *= 2;
  std::cout << "ref fun " << i << std::endl;
  return;
}

void ptr_fun( int* p ) {
  *p *= 2;
  std::cout << "ptr fun " << p << " " << *p << std::endl;
  return;
}

int main() {

  int i;
  std::cin >> i;
  ref_fun( i );
  std::cout << i << std::endl;
  std::cout << "==============" << std::endl;
  ptr_fun( &i );
  std::cout << i << std::endl;
  std::cout << "==============" << std::endl;
  return 0;

}
