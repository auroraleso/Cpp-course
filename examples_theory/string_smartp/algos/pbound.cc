using namespace std;

#include <iostream>
#include <algorithm>

int main() {

  int n = 15;
  int i;
  int* v = new int[n];
  v[ 0]=  1;
  v[ 1]=  3;
  v[ 2]=  5;
  v[ 3]=  7;
  v[ 4]=  9;
  v[ 5]=  9;
  v[ 6]= 12;
  v[ 7]=  9;
  v[ 8]= 12;
  v[ 9]= 14;
  v[10]= 16;
  v[11]= 18;
  v[12]= 20;
  v[13]= 25;
  v[14]= 30;

  sort( v, v + n );
  for ( i = 0; i < n; ++i ) cout << i << " " << v[i] << endl;

  int* iter_b = v;
  int* iter_e = v + 15;
  cout << distance( iter_b, iter_e ) << endl;

  while ( cin >> i ) {

    // the first element such that
    // it and all the following are not smaller than i
    // i.e. the smallest element not smaller than i
    // i.e. the first element equal to i or the next one
    int* iter_l = lower_bound( iter_b, iter_e, i );
    // the first element such that
    // it and all the following are bigger than i
    // i.e. the smallest element bigger than i
    // i.e. the next element after i
    int* iter_u = upper_bound( iter_b, iter_e, i );

    cout << "lb: " << distance( iter_b, iter_l ) << endl;
    cout << "ub: " << distance( iter_b, iter_u ) << endl;
    cout << distance( iter_l, iter_u ) << endl;
    if ( iter_l != iter_e ) cout << *iter_l;
    else                    cout << "*********";
    cout << " ";
    if ( iter_u != iter_e ) cout << *iter_u;
    else                    cout << "*********";
    cout << endl;

  }

  return 0;

}





