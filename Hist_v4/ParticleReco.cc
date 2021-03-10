#include "ParticleReco.h"
#include "Event.h"
#include "Utilities.h"
#include "Constants.h"
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

Event::pointpart loopPointer;
  double loopPx, loopPy, loopPz;
  int pos = 0;
  int neg = 0;

  double sumpx=0,sumpy=0,sumpz=0;
  
  //  for energy sums
  double EK0 = 0, ELambda0 = 0;
  
  //  for invariant masses
  double invK0 = 0,  invLambda0 = 0;

  
  for ( int i = 0; i < e.nParticles(); ++i ) {
    // get particle pointer
    loopPointer = e.getParticle(i);
	
	// get particle momentum components
	loopPx = loopPointer->px, loopPy = loopPointer->py, loopPz = loopPointer->pz;
	
    // update  sums
    sumpx += loopPx, sumpy += loopPy,	sumpz += loopPz;
	
    // update energy sums, for K0 and Lambda0 hypotheses:
    // pion mass for K0,
	EK0 += Utilities::energy( loopPx, loopPy, loopPz,
					           Constants::massPion );
    
	/* proton or pion mass for Lambda0,
     for positive or negative particles respectively and
     update positive/negative track counters*/
	if(loopPointer->q > 0){
		ELambda0 += Utilities::energy( loopPx, loopPy, loopPz,
			            				Constants::massProton );
		pos++;
	}else{
		ELambda0 += Utilities::energy( loopPx, loopPy, loopPz,
							            Constants::massPion );
		neg++;
	}
  }
  // check hypotesis (1 pos, 1 neg), if not satisfied return not physiscal results
  if( ( pos != 1 ) || ( neg !=1 ) )
   {
   totenergy=-1; //unphysical
   p=unknown;
   invmass=-1; //unphysical
   return;
 }

  // invariant masses for different decay product mass hypotheses
  invK0      = Utilities::invMass( sumpx, sumpy, sumpz,
						               EK0 );
  invLambda0 = Utilities::invMass( sumpx, sumpy, sumpz,
						               ELambda0 );
						

 /*compare invariant masses obtained, return the one which is closer to the
  known value*/
  double differenceK0 = fabs(Constants::massK0 - invK0);
  
  double differenceLambda0 = fabs(Constants::massLambda0 - invLambda0);

 if( differenceK0 > differenceLambda0 )
 {
   totenergy=ELambda0;
   p=Lambda0;
   invmass=invLambda0;
 }
 else
 {
   totenergy=EK0;
   p=K0;
   invmass=invK0;
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

