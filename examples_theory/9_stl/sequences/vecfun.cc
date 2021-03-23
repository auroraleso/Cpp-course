
// create a vector with all the elements set at 3
// add the index of each element at the element itself
// print all the elements
// print the first and last element
// remove the last element
// print again

using namespace std;
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ) {

  int n = 10; // create a vector with 10 elements
  vector<int> v( n, 3 );
  unsigned int i;
  for( i = 0; i < v.size(); ++i ) v[i] += i;
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "first: " << v.front() << " , last: " << v.back() << endl;
  cout << "*******" << endl;
  v.pop_back();        // remove the last element
  for( i = 0; i < v.size(); ++i ) cout << i << " " << v[i] << endl;
  cout << "first: " << v.front() << " , last: " << v.back() << endl;

  return 0;

}


