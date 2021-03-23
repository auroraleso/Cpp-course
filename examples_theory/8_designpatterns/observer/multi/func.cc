#include "SimpleDispatcher.h"
#include "IntPower.h"

void f( SimpleDispatcher<int>& d_e, SimpleDispatcher<int>& d_o ) {
  d_e.subscribe( new IntPower( 3 ) );
  d_e.subscribe( new IntPower( 5 ) );
  d_o.subscribe( new IntPower( 8 ) );
  return;
}
