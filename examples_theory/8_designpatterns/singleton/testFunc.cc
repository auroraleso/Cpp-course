#include "Base.h"
#include <iostream>
using namespace std;

int main() {

  Base* b = Base::instance();

  b->f();

  return 0;

}

