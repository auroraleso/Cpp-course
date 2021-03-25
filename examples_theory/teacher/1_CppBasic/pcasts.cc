
// force the modification of a non-const variable
// through a pointer-to-const variable

// force the modification of a     const variable
// through a pointer-to-const variable

// reinterpret a float as an int

#include <iostream>
#include <cmath>

int main() {

  int i = 123;
  std::cout << "before modification: " << i << std::endl;
  const int* p = &i;
  *const_cast<int*>( p ) = 234;
  std::cout << "after  modification: " << i << " " << *p << " "
                                       << p << std::endl;
  std::cout << std::endl;

  const
  int j = i;
  std::cout << "before modification: " << j << std::endl;
  const int* q = &j;
  *const_cast<int*>( q ) = 345;
  std::cout << "after  modification: " << j << " " << *q << " "
                                       << q << std::endl;
  std::cout << std::endl;

  const
  int k = 456;
  std::cout << "before modification: " << k << std::endl;
  const int* r = &k;
  *const_cast<int*>( r ) = 678;
  std::cout << "after  modification: " << k << " " << *r << " "
                                       << r << std::endl;
  std::cout << std::endl;

  float x = 23.45;
  int n = *reinterpret_cast<int*>( &x );
  std::cout << x << " " << n << std::endl;

  return 0;

}
