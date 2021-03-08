#include "LifeTimeFit.h"
#include "Event.h"
#include <math.h>
#include "ParticleReco.h"
double mass( const Event& ev);

LifeTimeFit::LifeTimeFit( double min, double max ):
 // initializations  
 min(min), max(max), acceptedev(0)
  {	 
}


LifeTimeFit::~LifeTimeFit() {
}

unsigned int LifeTimeFit::nEvents() const{
	return acceptedev;
}



// add data from a new event
bool LifeTimeFit::add( const Event& e ) {
	static ParticleReco* mass= ParticleReco::instance();
	float invMass=mass->mass();
    // check if accepted
	if( ( invMass < 0) ) return false;
  //|| ( invMass > ( max -min ) )
    // update counter
	acceptedev++;
	return true;
	
}
void LifeTimeFit::compute ()
{

}





