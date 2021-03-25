#include "AnalysisPlugins/BGCalc.h"

#include "AnalysisFramework/Event.h"
#include "AnalysisFramework/AnalysisInfo.h"
#include "AnalysisFramework/AnalysisFactory.h"
#include "AnalysisObjects/TotalEnergy.h"

#include <iostream>
#include <thread>
#include <cmath>

using namespace std;

// define a builder for this analyzer and register it
class BGCalcFactory: public AnalysisFactory::AbsFactory {
 public:
  BGCalcFactory(): AnalysisFactory::AbsFactory( "bg" ) {}
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new BGCalc( info );
  }
};
// create a global BGCalcFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// a BGCalcFactory will be available with name "bg".
static BGCalcFactory bg;

BGCalc::BGCalc( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


BGCalc::~BGCalc() {
}


void BGCalc::beginJob() {

  // min and max energy, min and max point, number of selected events
  eMin = 3000;
  eMax = 5000;
  bMin = 100;
  bMax = 120;

  // sum of energies and sum of square energies
  int n = aInfo->nThreads();
  nEvt.resize( n, 0 );
  bSum.resize( n, 0 );
  bSqr.resize( n, 0 );

  // create lazy observers
  // in principle this could be not strictly necessary, and the "instance"
  // function could be called everywhere the corresponding objects are
  // needed, but this would cause the overhead of the call to that function
  // each time, with all the checks it performs; moreover if called by
  // different threads synchronization issues arise
  totalE.resize( n );
  while ( n-- ) totalE[n] = TotalEnergy::instance( n );

  return;

}


void BGCalc::update( const Event& ev ) {

  // get thread id
  int id = EventSource::thrId( &ev );

  // total energy
  float eRaw = totalE[id]->rawSum();
  if ( eRaw < eMin ) return;
  if ( eRaw > eMax ) return;

  // loop over points and update sums
  int iBin;
  for ( iBin = bMin; iBin < bMax; ++iBin ) {
    int ene = ev.energy( iBin );
    bSum[id] +=   ene;
    bSqr[id] += ( ene * ene );
  }

  // update event counter
  ++nEvt[id];

  return;

}


void BGCalc::endJob() {

  // compute background

  // compute total sums
  unsigned int nThr = nEvt.size();
  unsigned int iThr;
  int tnEvt = 0;
  float tSum = 0.0;
  float tSqr = 0.0;
  // compute global sums
  for ( iThr = 0; iThr < nThr; ++iThr ) {
    tnEvt += nEvt[iThr];
    tSum  += bSum[iThr];
    tSqr  += bSqr[iThr];
  }

  // number of points
  int nBin = bMax - bMin;
  // total number of measurements
  int nTot = tnEvt * nBin;
  // compute mean and rms
  float bMean =          tSum * 1.0 / nTot;
  float bRMS  = sqrt ( ( tSqr * 1.0 / nTot ) - ( bMean * bMean ) );
  // printout result
  cout << tnEvt << endl;
  cout << "background " << bMean << " +- " << bRMS << endl;

  return;

}

