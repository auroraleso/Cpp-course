#include <iostream>

#include "Event.h"

bool add  ( const Event& ev, int eMin, int eMax,
            double* sum, double* sqr ) {

  int i;
  int s = 0;
  for ( i = 0; i < pointsMin; ++i ) s += ev.eLoss[i];
  if ( s < eMin ) return false;
  if ( s > eMax ) return false;

  int e;
  for ( i = 0; i < pointsMin; ++i ) {
    e = ev.eLoss[i];
    sum[i] += e;
    sqr[i] += e * e;
  }

  return true;

}

