#include "FloatArray.h"

#include <iostream>
using namespace std;

FloatArray append( const FloatArray& a, const FloatArray& b ) {
  cout << "now append" << endl;
  int na = a.size();
  int nb = b.size();
  if ( !na ) return b;
  if ( !nb ) return a;
  FloatArray c( na + nb );
  int i;
  for ( i = 0; i < na; ++i ) c[i     ] = a[i];
  for ( i = 0; i < nb; ++i ) c[i + na] = b[i];
  cout << "appended" << endl;
  return c;
}

int main() {

  unsigned int i;
  unsigned int n = 5;
  FloatArray a( n );
  for ( i = 0; i < n; ++i ) a[i] = i * 3.2;
  unsigned int m = 3;
  FloatArray b( m );
  for ( i = 0; i < m; ++i ) b[i] = i * 6.7;

  FloatArray c;
  cout << "****" << endl;
  c = append( a, b ); // a temporary object is returned to be copied onto c
  unsigned int s = c.size();
  for ( i = 0; i < s; ++i ) cout << i << " " << c[i] << endl;

  return 0;

}

