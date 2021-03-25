#include "FixedSizeArray.h"

#include <iostream>

using namespace std;

template <class T, unsigned int N>
void print( const FixedSizeArray<T,N> a ) {
  unsigned int i;
  unsigned int n = a.size();
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;
  cout << "***" << endl;
  return;
}

int main() {

  unsigned int i;
  FixedSizeArray<float,5> a;
  unsigned int n = a.size();
  for ( i = 0; i < n; ++i ) a[i] = i * 3.2;
  print( a );
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;

  return 0;

}

