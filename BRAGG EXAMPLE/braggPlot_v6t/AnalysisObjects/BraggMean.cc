#include "AnalysisObjects/BraggMean.h"
#include "AnalysisFramework/Event.h"
#include "AnalysisObjects/TotalEnergy.h"
#include "AnalysisUtilities/Constants.h"

#include <iostream>
#include <cmath>

using namespace std;

BraggMean::BraggMean( int minEnergy, int maxEnergy, int nThreads ):
  // initializations
  eMin( minEnergy ),
  eMax( maxEnergy ),
  tnEvt( 0 ) {
  unsigned int n = Event::minSize();
  // allocate arrays for sums, mean and rms: set size at min number of points
  // set at 0 all sums, means and rms
  totalE.resize( nThreads );
  nEvt  .resize( nThreads, 0 );
  sum   .resize( nThreads );
  sqr   .resize( nThreads );
  mean  .resize( n, 0.0 );
  rms   .resize( n, 0.0 );
  while ( nThreads-- ) {
    sum   [nThreads].resize( n, 0 );
    sqr   [nThreads].resize( n, 0 );
    totalE[nThreads] = TotalEnergy::instance( nThreads );
  }
}


BraggMean::~BraggMean() {
}


void BraggMean::add( const Event& ev, int thrId ) {

  // get total energy
  float energy = totalE[thrId]->energy();

  // check for total energy being in the required range,
  // if not return
  if ( energy < eMin ) return;
  if ( energy > eMax ) return;

  // loop over points and update sums for each point
  unsigned int i;
  unsigned int n = Event::minSize();
  vector<double>& tsum = sum[thrId];
  vector<double>& tsqr = sqr[thrId];
  for ( i = 0; i < n; ++i ) {
    float e = ev.energy( i );
    tsum[i] += e;
    tsqr[i] += e * e;
  }

  // update event counter
  ++nEvt[thrId];

  return;

}


void BraggMean::compute() {
  // compute total sums
  unsigned int n = Event::minSize();
  unsigned int i;
  unsigned int nThr = nEvt.size();
  unsigned int iThr;
  int tnEvt = 0;
  vector<double> tSum( n, 0.0 );
  vector<double> tSqr( n, 0.0 );
  // compute global sums
  for ( iThr = 0; iThr < nThr; ++iThr ) {
    tnEvt += nEvt[iThr];
    vector<double>& iSum = sum[iThr];
    vector<double>& iSqr = sqr[iThr];
    for ( i = 0; i < n; ++i ) {
      tSum[i] += iSum[i];
      tSqr[i] += iSqr[i];
    }
  }
  // loop over points and compute mean and rms for each point
  double m;
  double v;
  for ( i = 0; i < n; ++i ) {
    mean[i] = ( m = tSum[i] * 1.0 / tnEvt ) - Constants::bgMean;
    v       =     ( tSqr[i] * 1.0 / tnEvt ) - ( m * m );
    rms [i] = ( v > 0 ? sqrt( v ) : 0.0 );
  }
  return;
}


const vector<double>& BraggMean::eMean() const {
  return mean;
}


const vector<double>& BraggMean::eRMS()  const {
  return rms;
}

