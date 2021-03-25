#include <iostream>
#include <fstream>
#include <string>

#include "Event.h"
#include "BraggMean.h"

using namespace std;

//signatures functions
const Event* read( ifstream& file );
void dump( const Event& ev );

int main( int argc, char* argv[] ) {

  // open input file
  const string name = argv[1];
  ifstream file( name.c_str() );

  // create objects to compute mean and rms
  BraggMean background ( 3000, 5000 );
  BraggMean amaronium  ( 6000, 6499 );
  BraggMean barberium  ( 6500, 6799 );
  BraggMean cabernetium( 6800, 7200 );

  // loop over events
  const Event* ev;
  while ( ( ev = read( file ) ) != nullptr ) {
//    dump( *ev );
    background .add( *ev );
    amaronium  .add( *ev );
    barberium  .add( *ev );
    cabernetium.add( *ev );
    delete ev;
  }

  // compute mean and rms
  background .compute();
  amaronium  .compute();
  barberium  .compute();
  cabernetium.compute();

  // print results

  // mean and rms
  const vector<double>& backgroundMean  = background .eMean();
  const vector<double>& backgroundRMS   = background .eRMS();
  const vector<double>& amaroniumMean   = amaronium  .eMean();
  const vector<double>& amaroniumRMS    = amaronium  .eRMS();
  const vector<double>& barberiumMean   = barberium  .eMean();
  const vector<double>& barberiumRMS    = barberium  .eRMS();
  const vector<double>& cabernetiumMean = cabernetium.eMean();
  const vector<double>& cabernetiumRMS  = cabernetium.eRMS();
  unsigned int i;
  for ( i = 0; i < Event::minSize(); ++i )
    cout << i << " " << backgroundMean [i] << " " << backgroundRMS [i] << " | "
                     << amaroniumMean  [i] << " " << amaroniumRMS  [i] << " | "
                     << barberiumMean  [i] << " " << barberiumRMS  [i] << " | "
                     << cabernetiumMean[i] << " " << cabernetiumRMS[i] << endl;

  // number of selected events
  cout << background .nEvents() << " | "
       << amaronium  .nEvents() << " | "
       << barberium  .nEvents() << " | "
       << cabernetium.nEvents() << endl;

  return 0;

}

