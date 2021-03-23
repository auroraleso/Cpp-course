#include <stdlib.h>

#include <iostream>

float rr() {
  return ( random() * 1.0 /RAND_MAX ) - 0.5;
}

#define ABS(X) ( X>0?X:-X )

int main() {

  int i = 100;
  while ( i-- ) std::cout << ABS(rr()) << std::endl;
  return 0;

}

