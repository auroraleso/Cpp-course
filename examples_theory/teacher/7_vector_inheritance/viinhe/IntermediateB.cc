#include "IntermediateB.h"
#include <iostream>
using namespace std;

IntermediateB::IntermediateB( int i ):
 // specify Base is initialized from an IntermediateB object
 Base( i, "IntermediateB" ),
 k( 3 * i ) {
  cout << "IntermediateB created" << endl;
}

IntermediateB::~IntermediateB() {
}

  // a redefinition of this function, redeclared by IntermediateA too,
  // requires a redefinition in Derived, to disambiguate calls
//void IntermediateB::toBeRedefined() {
//  cout << "I'm in IntermediateB!" << endl;
//}

void IntermediateB::checkWhere() {
  cout << "... IntermediateB::checkWhere() ... ";
  toBeRedefined();
}
