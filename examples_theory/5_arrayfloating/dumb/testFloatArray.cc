#include "FloatArray.h"

#include <iostream>

using namespace std;

int main() {

  unsigned int i;
  unsigned int n = 5;
  FloatArray a( n );
  for ( i = 0; i < n; ++i ) a[i] = i * 3.2;
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;

  return 0;

}

