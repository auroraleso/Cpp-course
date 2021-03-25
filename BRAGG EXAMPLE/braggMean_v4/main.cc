#include <vector>
#include <string>
#include <sstream>

#include "Event.h"
#include "EventReadFromFile.h"
#include "EventSim.h"
#include "AnalysisSteering.h"
#include "ElementReco.h"
#include "EventDump.h"

using namespace std;

int main( int argc, char* argv[] ) {

  // create data source
  EventSource* es;
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

    /*
    -------------------------------STRINGSTREAM-------------------------------------
          A stringstream associates a string object with a stream allowing you to read from the
          string as if it were a stream (like cin).

          Basic methods are –

            clear() — to clear the stream
            str() — to get and set string object whose content is present in stream.
            operator << — add a string to the stringstream object.
            operator >> — read something from the stringstream object,
    */
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
  aList.push_back( new ElementReco );

  // initialize all analyzers
  for ( auto as: aList ) as->beginJob();

  // loop over events
  const Event* ev;
  while ( ( ev = es->get() ) != nullptr ) {
    for ( auto as: aList ) as->process( *ev );
    delete ev;
  }

  // finalize all analyzers
  for ( auto as: aList ) as->endJob();

  delete es;

  return 0;

}

