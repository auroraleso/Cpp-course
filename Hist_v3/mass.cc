#include <cmath>

#include "Event.h"
#include "Utilities.h"
#include "Constants.h"

double mass( const Event& e) {
  double sumpx=0,sumpy=0,sumpz=0;
  double loopPx, loopPy, loopPz;
  int pos=0,neg=0;
  Event::pointpart loopPointer;
    // storing energy sums
  double EK0 = 0, ELambda0 = 0;
  
  // storing inv masses
  double invK0 = 0, invLambda0 = 0;

  for ( int i = 0; i < e.nParticles(); ++i ) {
    // get particle pointer
    loopPointer = e.getParticle(i);
	
	//get components for momentum 
	loopPx = loopPointer->px, loopPy = loopPointer->py, loopPz = loopPointer->pz;
	//update sums
  sumpx += loopPx, sumpy += loopPy, sumpz += loopPz;
	
    //update energy sums for K0
	EK0 += Utilities::energy( loopPx, loopPy, loopPz,
					           Constants::massPion );
    
	//different cases for Lambda0, still updating energy sums
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
  // check for hypotesis satisfied (one neg and one pos), 
  //if not return negative value
  if( ( pos != 1 ) || ( neg !=1 ) ) return -1;

  // invariant masses for different decay product mass hypotheses
  invK0      = Utilities::invMass( sumpx, sumpy, sumpz,
						               EK0 );
  invLambda0 = Utilities::invMass( sumpx, sumpy, sumpz,
						               ELambda0 );
						

  // compare invariant masses obtained, return the one which is closer to the
  //known value
  double differenceK0 = fabs(Constants::massK0 - invK0);

 // differenceK0 =  (differenceK0 > 0 ) ? differenceK0 : -differenceK0;
  
  double differenceLambda0 = fabs(Constants::massLambda0 - invLambda0);
  //differenceLambda0 =  (differenceLambda0 > 0 ) ? differenceLambda0 : -differenceLambda0;
  
  if( differenceK0 > differenceLambda0 ) return invLambda0;
  return invK0;

}

