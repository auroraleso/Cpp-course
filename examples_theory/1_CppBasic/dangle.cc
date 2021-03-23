
// dangling pointer

#include <iostream>
#include <stdlib.h>

float* randptr() {
  float* p = new float( random() * 1.0 / RAND_MAX );
  return p;
}

void ptrprint( const float* p, float a, float b ) {
  std::cout << a + ( *p * ( b - a ) ) << std::endl;
  delete p;
  return;
}

int main() {

  int i;
  for ( i = 0; i < 10; ++i ) {
    float* p = randptr();
    ptrprint( p, 15.0, 18.0 ); // memory pointed by p is deallocated
    ptrprint( p, 21.0, 32.0 ); // p is still existing but invalid because deleted in the previous line!!
    
  }
  return 0;

}
