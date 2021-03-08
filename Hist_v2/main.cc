#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "AnalysisInfo.h"
#include "SourceFactory.h"
#include "Event.h"
#include "MassMean.h"
#include "EventReadFromFile.h"
#include "EventSim.h"
#include "AnalysisSteering.cpp"
#include "ParticleMass.h"
#include "EventDump.h"
#include "EventSource.h"

using namespace std;

int main( int argc, char* argv[] ) {
// store command line parameters
  AnalysisInfo* info = new AnalysisInfo( argc, argv );

  // create data source
  EventSource* es = SourceFactory::create( info );

  // create a list of analyzers
 
  const string type = argv[1];
  if ( type == "input" ) {
    const string name = argv[2];
    es = new EventReadFromFile( name );
  }
  else
  if ( type == "sim" ) {
    const string nevt = argv[2];
    const string seed = ( argc > 3 ? argv[3] : "1" );
    stringstream sstr;
    unsigned int n;
    sstr.str( nevt );
    sstr >> n;
    sstr.clear();
    unsigned int s;
    sstr.str( seed );
    sstr >> s;
    es = new EventSim( n, s );
  }
  else {
    cout << "invalid keyword" << endl;
    return 0;
  }
  
  // create a list of analyzers
  vector<AnalysisSteering*> aList;
  
  // create object to dump event
  // and store into list of analyzers
  aList.push_back( new EventDump );
  
  // create object to compute mean and rms energies
  // and store into list of analyzers
  aList.push_back( new ParticleMass );
  
  // initialize all analyzers
  for ( auto as: aList ) as->beginJob();
  
  // loop over events
  const Event* ev;
  while ( ( ev = es->get() ) != nullptr )  {
    for ( auto as: aList ) as->process( *ev );
	delete ev;
  }

  // finalize all analyzers
  for ( auto as: aList ) as->endJob();
  
  delete es;
		   
  return 0;

}
