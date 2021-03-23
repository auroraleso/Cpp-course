#include "LinkedList.h"

#include <iostream>

using namespace std;

int main() {

  LinkedList<int> ll;

  ll.insert( 3, ll.end() );
  ll.insert( 9, ll.end() );
  ll.insert( 5, ll.end() );
  ll.insert( 1, ll.end() );
  ll.insert( 7, ll.end() );

  LinkedList<int>::Iterator iter = ll.begin();
  LinkedList<int>::Iterator iend = ll.end();
  while ( iter != iend ) cout << *iter++ << endl;

  cout << endl;

  iter = ll.begin();
  ++iter;
  ++iter;
  ++iter;
  ll.insert( 2, iter );
  --iter;
  ll.insert( 4, iter );
  iter = ll.begin();
  ll.insert( 6, iter );

  iter = ll.begin();
  iend = ll.end();
  while ( iter != iend ) cout << *iter++ << endl;

  cout << endl;

  iter = ll.rbegin();
  iend = ll.rend();
  while ( iter != iend ) cout << *iter-- << endl;

  return 0;

}

