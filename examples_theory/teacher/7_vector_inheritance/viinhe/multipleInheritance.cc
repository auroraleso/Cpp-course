#include "Derived.h"
#include <iostream>
using namespace std;

int main() {

  IntermediateA* a = new IntermediateA( 16 );
  IntermediateB* b = new IntermediateB( 18 );
  Derived* d = new Derived( 5, 7 );

  cout << "***********" << endl;

  cout << "a->f(5) : ";
  a->f( 5 );
  cout << "b->f(6) : ";
  b->f( 6 );
  cout << "d->IntermediateA::f(2) : ";
  d->IntermediateA::f( 2 );
  cout << "d->IntermediateB::f(3) : ";
  d->IntermediateB::f( 3 );

  cout << "***********" << endl;

  cout << "b->checkWhere() : ";
  b->checkWhere();
  cout << "d->checkWhere() : ";
  d->checkWhere();

  IntermediateB* c = new Derived( 8, 9 );
  cout << "c->checkWhere() : ";
  c->checkWhere();

  return 0;

}

