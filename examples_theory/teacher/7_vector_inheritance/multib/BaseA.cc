#include "BaseA.h"
#include <iostream>
using namespace std;

BaseA::BaseA():
 n( 0 ) {
}

BaseA::~BaseA() {
}

void BaseA::f( int i ) {
  cout << "BaseA::f " << this << " " << i << endl;
}

void BaseA::g() {
  cout << "BaseA::g " << this << " " << ++n << endl;
}

