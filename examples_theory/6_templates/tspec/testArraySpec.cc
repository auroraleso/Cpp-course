#include "Array.h"

#include <iostream>

using namespace std;

int main() {

  unsigned int i;
  unsigned int n = 5;

  Array<float> a( n );
  for ( i = 0; i < a.size(); ++i ) a[i] = i * 3.2;
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;

  cout << endl;

  Array<bool> b( n );
  for ( i = 0; i < b.size(); ++i ) b[i] = ( ( i % 3 ) == 1 );
  for ( i = 0; i < n; ++i ) cout << i << " " << b[i] << endl;

  cout << endl;

  Array<double> c( n );
  for ( i = 0; i < c.size(); ++i ) c[i] = i * 6.78965;
  for ( i = 0; i < n; ++i ) cout << i << " " << c[i] << endl;

  return 0;

}

