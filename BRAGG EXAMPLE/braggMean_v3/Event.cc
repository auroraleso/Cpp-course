#include "Event.h"

// set the min (120) and max (128) number of points
unsigned int Event::sMin = 120;
unsigned int Event::sMax = 128;


Event::Event( int n ):
  // initializations
  evNumber( n ) {
  // allocate array to contain energies: reserve space for max number of points
  eLoss.reserve( sMax );
}


Event::~Event() {
}


void Event::add( int energyLoss ) {
  // check for max array size:
  // if max number of points not yet reached
  //   increase number of points and store new point energy
  // if max number of points already reached
  //   do nothing
  if ( eLoss.size() < sMax ) eLoss.push_back( energyLoss );
  return;
}


int Event::eventNumber() const {
  return evNumber;
}


unsigned int Event::dataSize() const {
  return eLoss.size();
}


int Event::energy( unsigned int i ) const {
  // check for required point being inside the array:
  // - if required point inside the array return its energy
  // - if not return -1
  if ( i < eLoss.size() ) return eLoss[i];
  return -1;
}


unsigned int Event::maxSize() {
  return sMax;
}


unsigned int Event::minSize() {
  return sMin;
}

