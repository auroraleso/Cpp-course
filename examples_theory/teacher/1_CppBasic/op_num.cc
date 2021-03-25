
// add the reading of a floating point number

// perform a division between integers with integer result
// perform a division between integers with floating point result
// perform a square root
// perform a square power
// round the floating point number
// write the result

// write greek PI

// add a number to a variable
// increment a variable
// write the result

#include <iostream>
#include <cmath>

int main() {

  int i,j,k;
  float x;
  std::cin >> i >> j >> k >> x;
  std::cout << "the original numbers: "
            << i << " " << j << " " << k << " " << x << std::endl;

  int l = i / j;
  float y = i / j;
  float z = i * 1.0 / j;
  std::cout << "divisions: "
            << l << " " << y << " " << z << std::endl;

  std::cout << "floating point operations" << std::endl;
  std::cout << sqrt( x ) << std::endl;
  std::cout << pow( x, 2 ) << std::endl;
  int t = x;
  int r = lround( x );
  std::cout << t << " " << r << std::endl;

  std::cout << M_PI << std::endl;

  std::cout << "pre-increment and post-increment" << std::endl;
  i += 20;
  std::cout << i << std::endl;

  int m = ++i; // equivalent to: i+=1 ; int m=i;
  std::cout << i << " " << m << std::endl;
  int n = i++; // equivalent to: int n=i ; i+=1;
  std::cout << i << " " << n << std::endl;

  return 0;

}
