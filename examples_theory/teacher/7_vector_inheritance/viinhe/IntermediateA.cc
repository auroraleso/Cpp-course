#include "IntermediateA.h"
#include <iostream>
using namespace std;

IntermediateA::IntermediateA( int i ):
 // specify Base is initialized from an IntermediateA object
 Base( i, "IntermediateA" ),
 k( 2 * i ) {
  cout << "IntermediateA created" << endl;
}

IntermediateA::~IntermediateA() {
}

void IntermediateA::toBeRedefined() {
  cout << "I'm in IntermediateA!" << endl;
}

