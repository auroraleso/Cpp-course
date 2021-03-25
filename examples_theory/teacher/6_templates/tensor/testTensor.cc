#include "Tensor.h"

#include <iostream>

using namespace std;

int main() {

  unsigned int i;
  unsigned int j;
  unsigned int k;

  Array<unsigned int> n( 2 );
  n[0] = 8;
  n[1] = 12;
  Tensor<2,float> a( n );
  cout << a.size()[0] << endl;
  cout << a.size()[1] << endl;
  cout << endl;
  for ( i = 0; i < n[0]; ++i ) {
    for ( j = 0; j < n[1]; ++j ) {
      a[i][j] = ( ( i + 1 ) * 100 ) + j + 1;
    }
  }
  for ( i = 0; i < n[0]; ++i ) {
    for ( j = 0; j < n[1]; ++j ) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;

  Array<unsigned int> p( 3 );
  p[0] = 3;
  p[1] = 12;
  p[2] = 8;
  Tensor<3,float> b( p );
  cout << b.size()[0] << endl;
  cout << b.size()[1] << endl;
  cout << b.size()[2] << endl;
  cout << endl;
  for ( i = 0; i < p[0]; ++i ) {
    for ( j = 0; j < p[1]; ++j ) {
      for ( k = 0; k < p[2]; ++k ) {
        b[i][j][k] = ( ( i + 1 ) * 10000 ) + ( ( j + 1 ) * 100 ) + k + 1;
      }
    }
  }
  for ( i = 0; i < p[0]; ++i ) {
    for ( j = 0; j < p[1]; ++j ) {
      for ( k = 0; k < p[2]; ++k ) {
        cout << b[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;

}

