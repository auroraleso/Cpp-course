
// iterate over a a std::vector and write the elements onto the screen

using namespace std;
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ) {

  unsigned int n = 10; // create a vector with 10 elements
  vector<int> v( n );
  unsigned int i;
  for( i = 0; i < n ; ++i ) v[i] = 2 * i;
  vector<int>::iterator it = v.begin();
  vector<int>::iterator ie = v.end();
  while( it < ie ) cout << *it++ << endl;

  return 0;

}


