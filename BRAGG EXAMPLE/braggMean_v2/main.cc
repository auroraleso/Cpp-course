#include <iostream>
#include <fstream>

#include "Event.h"
#include "BraggMean.h"

const Event* read( std::ifstream& file );
void dump( const Event& ev );

int main( int argc, char* argv[] ) {

  // open input file
  const char* name = argv[1];
  std::ifstream file( name );

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
  const double* backgroundMean  = background .eMean();
  const double* backgroundRMS   = background .eRMS();
  const double* amaroniumMean   = amaronium  .eMean();
  const double* amaroniumRMS    = amaronium  .eRMS();
  const double* barberiumMean   = barberium  .eMean();
  const double* barberiumRMS    = barberium  .eRMS();
  const double* cabernetiumMean = cabernetium.eMean();
  const double* cabernetiumRMS  = cabernetium.eRMS();
  unsigned int i;
  for ( i = 0; i < Event::minSize(); ++i )
    std::cout << i << " " << backgroundMean [i] << " "
                          << backgroundRMS  [i] << " | "
                          << amaroniumMean  [i] << " "
                          << amaroniumRMS   [i] << " | "
                          << barberiumMean  [i] << " "
                          << barberiumRMS   [i] << " | "
                          << cabernetiumMean[i] << " "
                          << cabernetiumRMS [i] << std::endl;

  // number of selected events
  std::cout << background .nEvents() << " | "
            << amaronium  .nEvents() << " | "
            << barberium  .nEvents() << " | "
            << cabernetium.nEvents() << std::endl;

  return 0;

}

