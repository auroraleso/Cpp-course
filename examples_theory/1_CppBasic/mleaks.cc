
// memory leak

#include <iostream>
#include <stdlib.h>

int main() {

  int i;
  for ( i = 0; i < 1000000; ++i ) {
    float* p = new float( random() * 1.0 / RAND_MAX );
    if ( ( i % 1000 ) == 0 ) std::cout << i << " " << *p << std::endl;
    // p is destroyed at iteration end, pointed memory no more accessible
  }
  return 0;

}
