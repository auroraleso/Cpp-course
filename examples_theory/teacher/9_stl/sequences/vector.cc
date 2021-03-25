
// create, fill and write onto the screen a std::vector of integer numbers
// remove the last element

using namespace std;
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ) {

  unsigned int n = 10; // create a vector with 10 elements
  vector<int> v( n );
  unsigned int i;
  for( i = 0; i < n ; ++i ) v[i] = 2 * i;
  v.push_back( 987 );  // add at the end
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "*******" << endl;
  vector<int>* p = &v;
  for( i = 0; i < p->size(); ++i ) cout << i << " " << p->at( i ) << endl;
  cout << "*******" << endl;
  vector<int> w;
  w = v;
  for( i = 0; i < w.size(); ++i ) cout << i << " " << w[i] << endl;

  return 0;

}


