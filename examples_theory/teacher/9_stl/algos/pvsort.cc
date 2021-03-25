
// create and sort an array of 2D vectors

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool rev( int i, int j ) {
  return i > j;
}

int main( int argc, char* argv[] ) {

  vector<int> v( 5 );
  v[0] =  96;
  v[1] =  54;
  v[2] = 118;
  v[3] =  37;
  v[4] =  66;

  sort( v.begin(), v.end() );
//  sort( v.begin(), v.end(), rev );

  unsigned int i;
  for( i = 0; i < v.size(); ++i ) {
    cout << i << " " << v[i] << endl;
  }

  return 0;

}


