#include "MassMean.h"
#include "Event.h"
#include <math.h>

double mass( const Event& ev);

MassMean::MassMean( double min, double max ):
 // initializations  
 min(min), max(max), 
 acceptedev(0), mean(0), rms(0),
 massum(0), squaresum(0)
  {	 
}


MassMean::~MassMean() {
}

unsigned int MassMean::nEvents() const{
	return acceptedev;
}

double MassMean::Mmean() const{
	return mean;
}
double MassMean::mRMS() const{
	return rms;
}


// add data from a new event
bool MassMean::add( const Event& e ) {

	double invMass = mass(e) - min;
    // check if accepted
	if( ( invMass < 0) || ( invMass > ( max -min ) ) ) return false;

    // update counter
	acceptedev++;
	massum += invMass;
	squaresum   += pow( invMass, 2 );
	return true;
	
}

void MassMean::compute() {
	mean = massum/( acceptedev*1.0) + min  ;
	rms  = sqrt( squaresum/( acceptedev*1.0 )- pow( (mean-min), 2 ));

}



