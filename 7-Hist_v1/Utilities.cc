#include <iostream>
#include <cmath>

#include "Utilities.h"

Utilities::Utilities(){
}

Utilities::~Utilities(){
}

// compute energy from momentum x,y,z components and invariant mass
double Utilities::energy( double px, double py, double pz, double invMass) {
  double pTotSq = pow( px, 2 ) + pow( py, 2 ) + pow( pz, 2 );
  return sqrt( pTotSq + pow( invMass, 2 ));
} 

// compute invariant mass from momentum x,y,z components and energy
double Utilities::invMass( double px, double py, double pz, double energy ) {
  double pTotSq = pow( px, 2 ) + pow( py, 2 ) + pow( pz, 2 );
  return sqrt(pow(energy,2) - pTotSq );
} 