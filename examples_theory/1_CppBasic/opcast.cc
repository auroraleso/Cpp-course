
// perform a division between integers with integer result
// perform a division between integers with floating point result
//         using type cast

#include <iostream>
#include <cmath>

int main() {

  int i,j;
  std::cin >> i >> j;
  std::cout << "the original numbers: "
            << i << " " << j << std::endl;

  int l = i / j;
  float x = i / j;
  float y = static_cast<float>( i ) / j;
  float z = i / static_cast<float>( j );
  std::cout << "divisions: "
            << l << " " << x << " " << y << " " << z << std::endl;

  return 0;

}
