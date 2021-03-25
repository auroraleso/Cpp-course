
// insert a segment of a vector into another one

using namespace std;
#include <iostream>
#include <vector>

template <class T> void print(vector<T>& v) {
  // sub-class of a template class: typename required
  typename vector<T>::iterator it = v.begin();
  typename vector<T>::iterator ie = v.end();
  while( it != ie ) cout << *it++ << endl;
  return;
}

/*
void print(vector<int>& v) {
  // sub-class of a specialized class: typename not required
  vector<int>::iterator it = v.begin();
  vector<int>::iterator ie = v.end();
  while( it != ie ) cout << *it++ << endl;
  return;
}
*/

int main( int argc, char* argv[] ) {

  unsigned int n = 10; // create a vector with 10 elements
  unsigned int i;
  vector<int> u( n );
  for( i = 0; i < n ; ++i ) u[i] = -2 * i;
  vector<int> v( n );
  for( i = 0; i < n ; ++i ) v[i] =  3 * i;
  vector<int>::iterator it = u.begin() + 3;
  vector<int>::iterator ie = it + 4;
  vector<int>::iterator iv = v.begin() + 5;
  v.insert( iv, it, ie );
  print( v );
  cout << "********" << endl;
  it = v.begin() + 7;
  ie = it + 3;
  v.erase( it, ie );
  print( v );

  return 0;

}


