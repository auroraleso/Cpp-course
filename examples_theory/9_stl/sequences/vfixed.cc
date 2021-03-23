
// create a sequence witha fixed number of elements

using namespace std;
#include <iostream>
#include <array>

int main( int argc, char* argv[] ) {

  array<int,10> v { 20, 18, 16, 14, 12, 10, 8, 6, 4, 2 };
  unsigned int i;
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;

  return 0;

}


