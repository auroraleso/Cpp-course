#include "EventDump.h"
#include "Event.h"
#include <iostream>

using namespace std;

EventDump::EventDump() {
}


EventDump::~EventDump() {
}


// function to be called at execution start
void EventDump::beginJob() {
  return;
}


// function to be called at execution end
void EventDump::endJob() {
  return;
}


// function to be called for each event
void EventDump::process( const Event& e ) {
cout << e.eventNumber() 
            << endl 
            << e.getx() <<" "<<  e.gety() << " "<< e.getz() 
            << endl<<e.nParticles() 
            << endl;

  for (int i = 0; i < e.nParticles() ; ++i) 
  cout <<  e.getParticle(i)->q << " "<< e.getParticle(i)->px <<" "<<  e.getParticle(i)->py << " "<<e.getParticle(i)->pz<<endl;

  return;
}

