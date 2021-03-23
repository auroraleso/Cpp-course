#include <iostream>
#include <cmath>

// ********* WARNING *********
// The following macro are to be used only as demonstration:
// they lack important protections to be used in real programs

#define SQUARE(X) (X*X)
#define PRINT(X) std::cout << #X << " = "\
                           <<  X << std::endl
#define B C
#define A B
#define C 987

int main() {
  int i = 2;
  int j = 3;
  std::cout << "i = " << i << " , "
            << "j = " << j << " , "
            << "SQUARE(i+j) = " << SQUARE(i+j) << std::endl;
  PRINT(SQUARE(i));
  std::cout << A << std::endl;
  return 0;
}

