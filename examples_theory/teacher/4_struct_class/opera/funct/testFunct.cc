
// a functor multiplying the argument by a factor

#include <iostream>

#include "Funct.h"

int main() {

   // create a Funct setting it at 3
   Func m( 3 );

   // call the Funct with 5.3
   std::cout << m( 5.3 ) << std::endl;

   return 0;

}
