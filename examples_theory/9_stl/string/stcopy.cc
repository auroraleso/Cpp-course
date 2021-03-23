#include <iostream>
#include <string>

using namespace std;

int main() {

  // create a string
  string s ( "abcdefghi" );
  cout << s << endl;

  // copy the string
  string t = s;
  cout << t << endl;

  // concatenate two strings
  string u = s + '/' + "1234";
  cout << u << endl;

  return 0;

}
