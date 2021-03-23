
// fill a std::set and test for some elements

using namespace std;
#include <iostream>
#include <set>

class Reverse {
 public:
  bool operator()( int l, int r ) { return l > r; }
};

int main( int argc, char* argv[] ) {

  Reverse r;
  set<int,Reverse> s( r );
  s.insert(  8 );
  s.insert(  2 );
  s.insert( 15 );
  s.insert( 33 );
  s.insert( 12 );
  s.insert( 27 );

  set<int>::const_iterator iter = s.begin();
  set<int>::const_iterator iend = s.end();
  while ( iter != iend ) {
    cout << "set element: " << *iter++ << endl;
  }
  cout << endl;

  int i;
  while ( cin >> i ) {
    if ( ( iter = s.find( i ) ) != iend ) cout << "found at "
                                               << distance( iter, iend )
                                               << " to end" << endl;
    else                                  cout << "not found" << endl;
  }

  return 0;

}


