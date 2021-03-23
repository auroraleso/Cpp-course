#include "Derived.h"
#include <iostream>
using namespace std;

// Derived inherits directly from Base, as 
// Base is a virtual base for both IntermediateA and IntermediateB
// Base object must be initialized directly from Derived object,
// the initialization in IntermediateA and/or IntermediateB are neglected
Derived::Derived( int i, int j ):
 // specify Base is initialized from a Derived object
 Base( i + j, "Derived" ),
 IntermediateA( i ),
 IntermediateB( j ) {
  cout << "Derived created with " << i << "+" << j << endl; 
}

Derived::~Derived() {
}

  // a redefinition of this function is needed to disambiguate calls
  // if it's redefined both by IntermediateA and IntermediateB
//void Derived::toBeRedefined() {
//  IntermediateA::toBeRedefined();
////  cout << "I'm in Derived!" << endl;
//}
