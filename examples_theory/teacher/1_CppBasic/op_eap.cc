
// compare equality and assignment operators

#include <iostream>
#include <cmath>

int main() {

  int i=7, j=9, k=0;
  std::cout << "the original numbers: "
            << i << " " << j << " " << k << std::endl;
  if ( i==j ) k+=1; // false
  if ( (i=j) ) k+=2; // true
  std::cout << "the final numbers: "
            << i << " " << j << " " << k << std::endl;

  return 0;

}
