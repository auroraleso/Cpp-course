#include "SimpleDispatcher.h"
#include <iostream>

using namespace std;
void f( SimpleDispatcher<int>& d_e, SimpleDispatcher<int>& d_o );
void g( SimpleDispatcher<int>& d_e, SimpleDispatcher<int>& d_o );


int main() {

  SimpleDispatcher<int> d_e;
  SimpleDispatcher<int> d_o;
 
  f( d_e, d_o );
  g( d_e, d_o );
  int i = 0;
  while ( i < 10 ) {
    cout << "****** " << i << " ******" << endl;
    if ( i % 2 ) d_o.notify( i );
    else         d_e.notify( i );
    ++i;
  }

  return 0;

}

