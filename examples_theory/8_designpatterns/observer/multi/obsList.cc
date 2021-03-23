#include "IntObserver.h"
#include "SimpleDispatcher.h"

IntObserver a( "Aldo"     );
IntObserver b( "Giovanni" );
IntObserver c( "Giacomo"  );

void g( SimpleDispatcher<int>& d_e, SimpleDispatcher<int>& d_o ) {
  d_o.subscribe( &a );
  d_o.subscribe( &b );
  d_e.subscribe( &c );
}
