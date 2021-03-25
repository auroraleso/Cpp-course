
// insert the 3 int read from keyboard into an array
// write the 3 array elements by using a "for" cycle
// write the 3 array elements by using a "while" cycle
// insert in the cycle "break" or "continue" instructions
// access the array elements by using pointers

#include <iostream>

int main() {

  int i,j,k;
  std::cin >> i >> j >> k;
  std::cout << i << " " << j << " " << k << std::endl;

  int a[3];
  a[0] = i;
  a[1] = j;
  a[2] = k;

  std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;

  int l;
  for( l = 0; l < 3; ++l ) std::cout << l << ":" << a[l] << " ";
  std::cout << std::endl;

  std::cout << " =================== " << std::endl;

  int* p = a;
  std::cout << "pointers: " << a << " " << p << std::endl;
  std::cout << "size: " << sizeof( a ) << " " << sizeof( p ) << std::endl;
  std::cout << *p << std::endl;
  std::cout << *(p+2) << std::endl;

  std::cout << " =================== " << std::endl;

  p = a + 3;
  while ( p-- > a ) std::cout << *p << " ";
  std::cout << std::endl;

  return 0;

}
