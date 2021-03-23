#include <iostream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ) {

  string s(argv[1]);

  // string length
  cout << s.length() << endl;

  // compare strings
  if ( s == "abcdef" ) cout << "equal" << endl;

  // look for a substring
  cout << s.find( "cde" ) << endl;
  cout << ( s.find( "cde" ) == string::npos ?
            "not " : "" ) << "found" << endl;

  return 0;

}
