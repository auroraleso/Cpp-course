#include <iostream>
#include <math.h>

extern int pointsMin;

void stat( int n,
           double* sum, double* sqr,
           double* mea, double* rms ) {

  int i;
  double m;
  double v;
  for ( i = 0; i < pointsMin; ++i ) {
    mea[i] = m = sum[i] * 1.0 / n;
    v      =   ( sqr[i] * 1.0 / n ) - ( m * m );
    rms[i] = ( v > 0 ? sqrt( v ) : 0.0 ); //if v>0 set rms[i] to sqrt(v), otherwise set it to zero
  }

  return;

}

