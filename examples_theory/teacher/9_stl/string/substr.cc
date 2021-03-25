#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

  // create a string
  string s ( "abcdefghi" );
  cout << s << endl;

  // insert a substring
  s.insert( 3, "zyx" );
  cout << s << endl;

  // exctract a substring
  string t = s.substr( 4, 2 );
  cout << t << endl;

  return 0;

}
