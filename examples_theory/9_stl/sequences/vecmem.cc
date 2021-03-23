
// create aan empty vector and add 10 elements 
// setting each one at 3 plus the index of the element itself
// print the size and reserved space each time
// print all the elements
// print the first and last element
// remove the last element
// print again

using namespace std;
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ) {

  unsigned int n = 10; // create a vector with 10 elements
  vector<int> v;
  v.reserve( 4 );
  unsigned int i;
  for( i = 0; i < n; ++i ) {
    v.push_back( 3 + i );
    cout << "size: " << v.size()
         << " , reserved space: " << v.capacity() << endl;
  }
  cout << "*******" << endl;
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "first: " << v.front() << " , last: " << v.back() << endl;
  cout << "*******" << endl;
  v.pop_back();        // remove the last element
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "first: " << v.front() << " , last: " << v.back() << endl;
  cout << "*******" << endl;
  v.resize( 15, 999 );
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "first: " << v.front() << " , last: " << v.back() << endl;
  return 0;

}


