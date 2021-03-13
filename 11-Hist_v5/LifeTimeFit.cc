#include "LifeTimeFit.h"
#include "Event.h"
#include <math.h>
#include "ParticleReco.h"
#include "ProperTime.h"
#include "QuadraticFitter.h"
double mass( const Event& ev); 

LifeTimeFit::LifeTimeFit( double min, double max, double minTime, double maxTime, double minScan, double maxScan, double scanStep ):
 // initializations  
 min(min), max(max), 
 minTime(minTime), maxTime(maxTime), 
 minScan(minScan), maxScan(maxScan), 
 scanStep(scanStep)
{	 
}


LifeTimeFit::~LifeTimeFit() {
}

unsigned int LifeTimeFit::nEvents() const
{
	//return number of entries in the vector decaytimes
	return decaytimes.size();
}



// add data from a new event
bool LifeTimeFit::add( const Event& e ) {
	static ParticleReco* mass= ParticleReco::instance();
	float invMass=mass->mass();
	if( ( invMass < min) || invMass > max ) return false;

	static ProperTime* t=ProperTime::instance();
	 double dTime= t->DecayTime();
    // check if accepted
	if (dTime<maxTime && dTime>minTime)
	//if accepted it goes into the vector that stores decay times
	decaytimes.push_back(dTime);
	
	return true;
	
}
void LifeTimeFit::compute ()
{
	//with a max Likelyhood fit I compute the mean LifeTime and the relative error
	QuadraticFitter* parab=new QuadraticFitter();
	
	double t_s, L_ts;
	for (double n=1; n<(maxScan-minScan)/scanStep; n+=1)
{	
	 t_s=scanStep*n;
	 L_ts=0;
	for (unsigned int j=0; j<decaytimes.size();j++)
	{
		
		double p=decaytimes.at(j)/t_s + log(t_s) + log( exp(-minTime/t_s) - exp(-maxTime/t_s));
		L_ts=L_ts+p;

	}
   parab->add(t_s,L_ts);

}
}




double LifeTimeFit::lifeTime()
{
	QuadraticFitter b,c;
	double bi=b.b();
	double ci=c.c();
	return meanLifeTime=-bi/(2*ci);
}

double LifeTimeFit::lifeTimeError()
{
	QuadraticFitter c;
	double ci=c.c();
	return errorMeanLifeTime=1/sqrt(2*ci);
}