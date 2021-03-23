#include "Base.h"
#include <iostream>
using namespace std;

Base::Base( int i, const string& dname ):
 n( i ) {
  cout << "Base created from " << dname << " " << n << endl;
}

Base::~Base() {
}

void Base::f( int i ) {
  cout << "Base::f " << this << " " << i * n << endl;
}

void Base::toBeRedefined() {
  cout << "I'm in Base!" << endl;
}

