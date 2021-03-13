#include "ParticleReco.h"
#include <iostream>
#include <cmath>

using namespace std;

// constructor
ParticleReco::ParticleReco() {
}


// destructor
ParticleReco::~ParticleReco() {
}


// recompute tag informations for new event
void ParticleReco::update( const Event& e ) {

  // set default quantities
   p   = unknown;
  totenergy = -1.0;
  invmass   = -1.0;

Event::pointpart pointerloop;
  double loopPx, loopPy, loopPz;
  int plus = 0;
  int minus = 0;

  double sumpx=0,sumpy=0,sumpz=0;
  
  // variables for energy sums
  double K0e = 0, Lambda0e = 0;
  
  // variables for invariant mass
  double ifK0 = 0,  ifLambda0 = 0;

 // code to compute total energy and invariant mass for the two
  // mass hypotheses for the decay products

  // loop over particles - momenta
  
  for ( int i = 0; i < e.nParticles(); ++i ) {
    // get particle pointer
    pointerloop = e.getParticle(i);
	
	// get particle momentum components
	loopPx = pointerloop->px;
	loopPy = pointerloop->py;
	loopPz = pointerloop->pz;
	
    // update momentum sums
    sumpx += loopPx;
	sumpy += loopPy;
	sumpz += loopPz;
	
    // update energy sums, for K0 and Lambda0 hypotheses:
    // pion mass for K0,
	K0e += Utilities::energy( loopPx, loopPy, loopPz,
					           Constants::massPion );
    
	// proton or pion mass for Lambda0,
    // for positive or negative particles respectively and
    // update positive/negative track counters
	if(pointerloop->q > 0){
		Lambda0e += Utilities::energy( loopPx, loopPy, loopPz,
			            				Constants::massProton );
		plus++;
	}else{
		Lambda0e += Utilities::energy( loopPx, loopPy, loopPz,
							            Constants::massPion );
		minus++;
	}
  }
  // check for exactly one positive and one negative track
  // otherwise return negative ( not physical) invariant mass
  if( ( plus != 1 ) || ( minus !=1 ) )
   {
   totenergy=-1; //unphysical
   p=unknown;
   invmass=-1; //unphysical
   return;
 }

  // invariant masses for different decay product mass hypotheses
  ifK0      = Utilities::invMass( sumpx, sumpy, sumpz,
						               K0e );
  ifLambda0 = Utilities::invMass( sumpx, sumpy, sumpz,
						               Lambda0e );
						

  // compare invariant masses with known values and set final values
  double differenceK0 = Constants::massK0 - ifK0;
  differenceK0 =  (differenceK0 > 0 ) ? differenceK0 : -differenceK0;
  
  double differenceLambda0 = Constants::massLambda0 - ifLambda0;
  differenceLambda0 =  (differenceLambda0 > 0 ) ? differenceLambda0 : -differenceLambda0;
  // ( type, energy and mass )
 if( differenceK0 > differenceLambda0 )
 {
   totenergy=Lambda0e;
   p=Lambda0;
   invmass=ifLambda0;
 }
 else
 {
   totenergy=K0e;
   p=K0;
   invmass=ifK0;
 }
 
  return;

}

// return particle energy
  double ParticleReco::energy(){
  // check for new event and return result
     check();
     
return totenergy;
 
 
}
// return particle type
ParticleReco::ParticleType ParticleReco::ptype() {
  // check for new event and return result
   check();
   return p;

}





// return particle mass
double ParticleReco::mass() {
 check();
return invmass;
}

