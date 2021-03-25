#include "Array.h"

#include <iostream>

using namespace std;

template <class T>
void print( const Array<T> a ) {
  cout << "Position" << " " << "Value"<< endl;
  unsigned int i;
  unsigned int n = a.size();
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;
  cout << "***" << endl;
  return;
}

int main() {

  unsigned int i;
  unsigned int n = 5;
  Array<float> a( n );
  for ( i = 0; i < n; ++i ) a[i] = i * 3.2;
  print( a );
  for ( i = 0; i < n; ++i ) cout << i << " " << a[i] << endl;

  return 0;

}

