#include <iostream>
#include "FloatArray.h"

using namespace std;

float operator*( const FloatArray& x, const FloatArray& y ) {
  unsigned int i;
  unsigned int n = x.size();
  unsigned int m = y.size();
  if ( n > m ) n = m;
  float s = 0.0;
  for ( i = 0; i < n; ++i ) s += ( x[i] * y[i] );
  return s;
}

template <class T,class S>
auto mult( const T& x, const S& y ) -> decltype( x * y ) {
  return x * y;
}

int main() {

  int i = 12;
  int j = 23;
  int k = mult( i, j );
  cout << i << " * " << j << " = " << k << endl;

  float x = 1.23;
  float y = 2.34;
  float z = mult( x, y );
  cout << x << " * " << y << " = " << z << endl;

  FloatArray a( 2 );
  a[0] = 23.4;
  a[1] = 34.5;
  FloatArray b( 3 );
  b[0] = 45.6;
  b[1] = 56.7;
  b[2] = 67.8;
  unsigned int p;
  float c = mult( a, b );
  for ( p = 0; p < a.size(); ++p ) cout << a[p] << " ";
  cout << endl;
  for ( p = 0; p < b.size(); ++p ) cout << b[p] << " ";
  cout << endl;
  cout << "---> " << c << endl;

  return 0;

}

