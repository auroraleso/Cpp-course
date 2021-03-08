#include "EventDump.h"
#include "Event.h"
#include<iostream>
using namespace std;

EventDump::EventDump() {
}


EventDump::~EventDump() {
}


// executed at the beginning
void EventDump::beginJob() {
  return;
}


// executed at the end
void EventDump::endJob() {
  return;
}


void EventDump::process( const Event& e ) {

	// print data of event e, repeated for each event
	cout << e.eventNumber() << endl;
	cout << e.getx() << " "
		      << e.gety() << " "
			  << e.getz() << endl;
	 
	cout << e.nParticles()<<endl;
	
	for( int i = 0; i < e.nParticles(); ++i){
		cout << e.getParticle(i)->q << " "
				  << e.getParticle(i)->px << " "
				  << e.getParticle(i)->py << " "
				  << e.getParticle(i)->pz << endl;
	}

	return;

}

