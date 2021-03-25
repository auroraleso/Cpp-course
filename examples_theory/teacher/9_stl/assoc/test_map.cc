
// fill a std::set and test for some elements

using namespace std;
#include <iostream>
#include <string>
#include <map>

int main( int argc, char* argv[] ) {

  string mode = "";
  if ( argc > 1 ) mode = argv[1];

  map<string,int> m;

  if ( mode == "insert" ) {
    // use "insert"
    cout << "fill map by calling \"insert\" functions" << endl;
    m.insert( make_pair( "triangle" , 3 ) );
    m.insert( make_pair( "square"   , 4 ) );
    m.insert( make_pair( "rectangle", 4 ) );
    m.insert( make_pair( "pentagon" , 5 ) );
    m.insert( make_pair( "hexagon"  , 6 ) );
    m.insert( make_pair( "heptagon" , 7 ) );
    m.insert( make_pair( "octagon"  , 8 ) );
  }
  else
  if ( mode == "[]" ) { 
    // use []
    cout << "fill map by calling \"[]\" operator" << endl;
    m["triangle" ] = 3;
    m["square"   ] = 4;
    m["rectangle"] = 4;
    m["pentagon" ] = 5;
    m["hexagon"  ] = 6;
    m["heptagon" ] = 7;
    m["octagon"  ] = 8;
  }
  else {
    cout << "unvalid mode, choose \"insert\" or \"[]\"" << endl;
    return 0;
  }
  cout << endl;

  cout << "************" << endl;
  cout << "the map has " << m.size() << " elements" << endl;
  map<string,int>::const_iterator iter = m.begin();
  map<string,int>::const_iterator iend = m.end();
  while ( iter != iend ) {
    const pair<string,int>& entry = *iter++;
    cout << entry.first  << " is associated to "
         << entry.second << endl;
  }
  cout << endl;

  string s;
  cout << "look for elements via \"find\":" << endl;
  while ( cin >> s ) {
    if ( s == "-" ) break;
    if ( ( iter = m.find( s ) ) != iend ) {
      const pair<string,int>& entry = *iter;
      cout << entry.first  << " is associated to "
           << entry.second << endl;
    }
    else {
      cout << "not found" << endl;
    }
  }
  cout << endl;

  cin.clear();

  cout << "look for elements via \"[]\":" << endl;
  while ( cin >> s ) {
    cout << s << " is associated to " << m[s] << endl;
  }
  cout << endl;

  cout << "************" << endl;
  cout << "the map has " << m.size() << " elements" << endl;
  iter = m.begin();
  iend = m.end();
  while ( iter != iend ) {
    const pair<string,int>& entry = *iter++;
    cout << entry.first  << " is associated to "
         << entry.second << endl;
  }
  cout << endl;

  return 0;

}


