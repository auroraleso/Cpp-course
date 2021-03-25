#include <iostream>
#include <fstream>

// a "forward declaration" is sufficient,
// only a pointer to Event is used in the following
struct Event;
extern int pointsMin;

const Event* read( std::ifstream& file );
void dump ( const Event& ev );
bool add  ( const Event& ev, int eMin, int eMax,
            double* sum, double* sqr );
void clear( const Event* ev );
void stat( int n,
           double* sum, double* sqr,
           double* mea, double* rms );

int main( int argc, char* argv[] ) {

  // open input file
  const char* name = argv[1];
  std::ifstream file( name );

  // create arrays for sum of energies and sum of squares
  double* sum = new double[pointsMin];
  double* sqr = new double[pointsMin];
  int i;
  for ( i = 0; i < pointsMin; ++i ) sum[i] = sqr[i] = 0;

  // loop over events
  int n = 0;
  const Event* ev;
  while ( ( ev = read( file ) ) != nullptr ) {
//    dump( *ev );
    if ( add( *ev, 6000, 7500, sum, sqr ) ) ++n;
    clear( ev );
  }

  // create arrays for mean and rms
  double* mea = new double[pointsMin];
  double* rms = new double[pointsMin];

  // compute mean and rms
  stat( n, sum, sqr, mea, rms );

  // print results

  // mean and rms
  for ( i = 0; i < pointsMin; ++i )
    std::cout << i << " " << mea[i] << " " << rms[i] << std::endl;

  // number of selected events
  std::cout << n << std::endl;

  return 0;

}

