
// function returning the address of a local variable (WRONG)

#include <iostream>

int* ptr_ret( int i ) {
  int j = i * 2;
  std::cout << "ptr return " << j << " " << &j << std::endl;
  return &j; // WRONG, j is destroyed when the function returns
}

int main() {

  int i;
  std::cin >> i;
  int* p = ptr_ret( i );
  std::cout <<  p << std::endl;
  std::cout << *p << std::endl; // *p is now garbage, this could printout
                                // anything; if the memory has not yet
                                // overwritten the correct value is sent 
                                // to output, but that's random
  return 0;

}
