#include "RecursiveTree.h"

#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] ) {

  // open file
  ifstream file( argv[1] );

  // create tree
  RecursiveTree<char,int> rt;

  // read the file and count characters
  char c;
  while ( file.read( &c, 1 ) ) rt.find( c, 0 ).content++;

  // loop over characters and print number of occurrences
  RecursiveTree<char,int>::Iterator iter = rt.begin();
  RecursiveTree<char,int>::Iterator iend = rt.end();
  while ( iter != iend ) {
    // get element
    RecursiveTree<char,int>::Association& a = *iter++;
    // for ASCII codes between 32 and 126 print the character,
    // for others print the code
    ( ( ( c = a.key ) > 31  ) && 
      ( ( c = a.key ) < 127 ) ? cout << "++" << c
                              : cout << "++" << static_cast<int>( c ) )
                                     << "++ " << a.content << endl;
  }
  cout << endl;

  return 0;

}

