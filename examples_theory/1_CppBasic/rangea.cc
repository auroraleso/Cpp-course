
// C++11 code
// loop over an array

#include <iostream>

int main() {

  int i[12] { 7, 6, 5, 4, 3, 2, 1, 0, 11, 10, 9, 8 };

  for ( int j: i ) std::cout << j << " "; // loop over array elements
  std::cout << std::endl;

  int k = 0;
  for ( int& j: i ) j = 2 * k++;          // to change array elements
                                          // they must accessed by reference

  for ( int j: i ) std::cout << j << " "; // new loop over array elements
  std::cout << std::endl;

  return 0;

}
