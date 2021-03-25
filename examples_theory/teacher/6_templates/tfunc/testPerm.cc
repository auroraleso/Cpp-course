#include <iostream>
#include "FloatArray.h"

using namespace std;

template <class T>
void perm( T& x, T& y, T& z ) {
  T t = x;
  x = y;
  y = z;
  z = t;
//  cout << x.size() << " " << y.size() << " " << z.size() << endl;
  return;
}

int main() {

  int i = 12;
  int j = 23;
  int k = 34;
  cout << i << " " << j << " " << k << endl << "----" << endl;
  perm( i, j, k );
  cout << i << " " << j << " " << k << endl << "****" << endl;

  float x = 1.23;
  float y = 2.34;
  float z = 3.45;
  cout << x << " " << y << " " << z << endl << "----" << endl;
  perm( x, y, z );
  cout << x << " " << y << " " << z << endl << "****" << endl;

  FloatArray a( 2 );
  a[0] = 23.4;
  a[1] = 34.5;
  FloatArray b( 3 );
  b[0] = 45.6;
  b[1] = 56.7;
  b[2] = 67.8;
  FloatArray c( 4 );
  c[0] = 78.9;
  c[1] = 89.1;
  c[2] = 91.2;
  c[3] = 12.3;
  unsigned int p;
  for ( p = 0; p < a.size(); ++p ) { cout << a[p] << " "; } cout << endl;
  for ( p = 0; p < b.size(); ++p ) { cout << b[p] << " "; } cout << endl;
  for ( p = 0; p < c.size(); ++p ) { cout << c[p] << " "; } cout << endl;
  cout << "----" << endl;
  perm( a, b, c );
  for ( p = 0; p < a.size(); ++p ) { cout << a[p] << " "; } cout << endl;
  for ( p = 0; p < b.size(); ++p ) { cout << b[p] << " "; } cout << endl;
  for ( p = 0; p < c.size(); ++p ) { cout << c[p] << " "; } cout << endl;
  cout << "****" << endl;

  return 0;

}

