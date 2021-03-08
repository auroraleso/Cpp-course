#include <cmath>

#include "Event.h"
#include "Utilities.h"
#include "Constants.h"

double mass( const Event& e) {

  Event::pointpart pointerloop;
  double loopPx, loopPy, loopPz;
  int plus = 0;
  int minus = 0;

  double sumpx=0,sumpy=0,sumpz=0;
  
  // variables for energy sums, for K0 and Lambda0
  double K0e = 0, Lambda0e = 0;
  
  // variables for invariant mass, for K0 and Lambda0
  double ifK0 = 0;
  double ifLambda0 = 0;

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
  // otherwise return negative (unphysical) invariant mass
  if( ( plus != 1 ) || ( minus !=1 ) ) return -1;

  // invariant masses for different decay product mass hypotheses
  ifK0      = Utilities::invMass( sumpx, sumpy, sumpz,
						               K0e );
  ifLambda0 = Utilities::invMass( sumpx, sumpy, sumpz,
						               Lambda0e );
						

  // compare invariant masses with known values and return the nearest one
  double differenceK0 = Constants::massK0 - ifK0;
  differenceK0 =  (differenceK0 > 0 ) ? differenceK0 : -differenceK0;
  
  double differenceLambda0 = Constants::massLambda0 - ifLambda0;
  differenceLambda0 =  (differenceLambda0 > 0 ) ? differenceLambda0 : -differenceLambda0;
  
  if( differenceK0 > differenceLambda0 ) return ifLambda0;
  return ifK0;

}

