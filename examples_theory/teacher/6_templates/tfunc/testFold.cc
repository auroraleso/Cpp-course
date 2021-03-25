#include <iostream>
#include <cmath>

using namespace std;

template <class ... T>
void print( T ... t ) {
  (( cout << t << ' '),...) << endl;
  return;
}

int main() {

  print( 23, M_PI, "pippo" );
  cout << "*******" << endl;
  print( exp( 1.0 ), '\n', 0xff );
  cout << "*******" << endl;
  print( 97 );
  cout << "*******" << endl;
  print( 'b', 765.432 );

  return 0;

}
