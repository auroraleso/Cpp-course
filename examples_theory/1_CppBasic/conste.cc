
// C++11 code
// compile time constants

#include <iostream>
#include <cmath>

constexpr int f(int i, int j) {
  return i * j;
}
int main() {
  constexpr int i = 3;
  int j;
  std::cin >> j;
  std::cout << i * j << std::endl;
  constexpr int k = f( i, 5 );

  /*
  --------------------------------------DEF OF CONSTEXPR-------------------------------------------------
      The constexpr specifier declares that it is possible to evaluate the value of the function 
      or variable at compile time. Such variables and functions can then be used where only 
      compile time constant expressions are allowed (provided that appropriate function arguments are given).
      */
  std::cout << k << std::endl;
  return 0;
}

