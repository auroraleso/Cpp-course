#include "Dispatcher.h"
#include <iostream>

int main() {

  int i = 0;
  while ( i < 100 ) Dispatcher<int>::notify( i++ );

  return 0;

}

