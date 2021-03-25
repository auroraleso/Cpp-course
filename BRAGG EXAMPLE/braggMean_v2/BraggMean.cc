#include "BraggMean.h"
#include "Event.h"
#include <iostream>
#include <math.h>

BraggMean::BraggMean( int minEnergy, int maxEnergy ):
  // initializations
  eMin( minEnergy ),
  eMax( maxEnergy ),
  nEvt( 0 ) {
  unsigned int n = Event::minSize();
  // allocate arrays for sums, mean and rms: set size at min number of points
  sum  = new double[n];
  sqr  = new double[n];
  mean = new double[n];
  rms  = new double[n];
  // set at 0 all sums, means and rms
  unsigned int i;
  for ( i = 0; i < n; ++i ) mean[i] = rms[i] = sum[i] = sqr[i] = 0;
}


BraggMean::~BraggMean() {
  // free dynamic memory
  delete[] sum;
  delete[] sqr;
  delete[] mean;
  delete[] rms;
}


void BraggMean::add( const Event& ev ) {

  // loop over the min number of points and compute total energy
  unsigned int i;
  unsigned int n = Event::minSize();
  int s = 0;
  for ( i = 0; i < n; ++i ) s += ev.energy( i );

  // check for total energy being in the required range,
  // if not return
  if ( s < eMin ) return;
  if ( s > eMax ) return;

  // loop over points and update sums for each point
  for ( i = 0; i < n; ++i ) {
    float e = ev.energy( i );
    sum[i] += e;
    sqr[i] += e * e;
  }

  // update event counter
  ++nEvt;

  return;

}


void BraggMean::compute() {
  // loop over points and compute mean and rms for each point
  double m;
  double v;
  unsigned int n = Event::minSize();
  unsigned int i;
  for ( i = 0; i < n; ++i ) {
    mean[i] = m = sum[i] * 1.0 / nEvt;
    v       =   ( sqr[i] * 1.0 / nEvt ) - ( m * m );
    rms [i] = ( v > 0 ? sqrt( v ) : 0.0 );
  }
  return;
}


const double* BraggMean::eMean() const {
  return mean;
}


const double* BraggMean::eRMS()  const {
  return rms;
}

