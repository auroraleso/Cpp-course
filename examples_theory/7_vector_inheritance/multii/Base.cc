#include "Base.h"
#include <iostream>
using namespace std;

Base::Base( int i ):
 n( i ) {
}

Base::~Base() {
}

void Base::f( int i ) {
  cout << "Base::f " << this << " " << i * n << endl;
}

