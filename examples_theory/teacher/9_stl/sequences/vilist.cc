
// initialize a std::vector of integer numbers from a list

using namespace std;
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ) {

  vector<int> v { 20, 18, 16, 14, 12, 10, 8, 6, 4, 2 };
  unsigned int i;
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << v.capacity() << endl;
  cout << "===========" << endl;
  v.push_back( 987 );
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << v.capacity() << endl;

  return 0;

}


