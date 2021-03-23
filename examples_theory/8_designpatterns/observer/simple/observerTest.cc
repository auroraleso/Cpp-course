#include "SimpleDispatcher.h"

void f();


int main() {

  f();
  int i = 0;
  while ( i < 10 ) SimpleDispatcher<int>::notify( i++ );

  return 0;

}

