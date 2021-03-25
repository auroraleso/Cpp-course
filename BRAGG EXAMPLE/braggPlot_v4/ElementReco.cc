#include "ElementReco.h"

#include "Event.h"
#include "AnalysisInfo.h"
#include "AnalysisFactory.h"
#include "BraggMean.h"

#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// concrete factory to create an ElementReco analyzer
class ElementRecoFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "plot" as name for this analyzer and factory
  ElementRecoFactory(): AnalysisFactory::AbsFactory( "plot" ) {}
  // create an ElementReco when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ElementReco( info );
  }
};
// create a global ElementRecoFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an ElementRecoFactory will be available with name "plot".
static ElementRecoFactory er;

ElementReco::ElementReco( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


ElementReco::~ElementReco() {
}


// function to be called at execution start
void ElementReco::beginJob() {

  // create energy distributions for different total energy ranges
  bCurve.reserve( 10 );
  bCreate( "background" , 3000.0, 5000.0 );
  bCreate( "amaronium"  , 6000.0, 6499.0 );
  bCreate( "barberium"  , 6500.0, 6799.0 );
  bCreate( "cabernetium", 6800.0, 7200.0 );
  return;

}


// function to be called at execution end
void ElementReco::endJob() {

  // save current working area
  TDirectory* currentDir = gDirectory;
  // open histogram file
  TFile* file = new TFile( aInfo->value( "plot" ).c_str(), "CREATE" );

  // fill distributions with mean and rms energies

  // number of points
  int nBinD = Event::minSize();
  int iBinD;

  // loop over elements
  for ( BraggCurve* bParticle: bCurve ) {
    // get Bragg curve informations:
    // mean and rms energies and energy loss graph
    BraggMean* bMean = bParticle->bMean;
    TH1F*      hMean = bParticle->hMean;
    // compute results
    bMean->compute();
    // get mean and rms energies
    const vector<double>& mean = bMean->eMean();
    const vector<double>& rms  = bMean->eRMS ();
    // loop over points
    for ( iBinD = 0; iBinD < nBinD; ++iBinD ) {
      // print results
//      cout << iBinD << " " << mean[iBinD] << " " << rms[iBinD] << endl;
      // set center and error values in the graph
      // by using SetBinContent and SetBinError, bin count starts from 1
      hMean->SetBinContent( iBinD + 1, mean[iBinD] );
      hMean->SetBinError  ( iBinD + 1, rms [iBinD] );
    }
    // print number of events
//    cout << bMean->nEvents() << endl;
    // save distribution
    hMean->Write();
  }

  // close file
  file->Close();
  delete file;
  // restore working area
  currentDir->cd();

  return;

}


// function to be called for each event
void ElementReco::update( const Event& ev ) {
  // loop over energy distributions and pass event to each of them
  for ( BraggCurve* bParticle: bCurve ) bParticle->bMean->add( ev );
  return;
}


// create objects for a Bragg curve
void ElementReco::bCreate( const string& name, float min, float max ) {

  // create energy distribution for events with total energy in given range

  // create name for TH1F object
  const char* hName = name.c_str();

  // bin number equal to point number
  int nBinD = Event::minSize();

  // create TH1F and statistic objects and store their pointers
  BraggCurve* bc = new BraggCurve;
  bc-> name = name;
  bc->bMean = new BraggMean( min, max );
  bc->hMean = new TH1F( hName, hName, nBinD, 0.5, nBinD + 0.5 );
  bCurve.push_back( bc );

  return;

}

