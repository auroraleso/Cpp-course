#include <iostream>
#include <cmath>

using namespace std;

void print() {
  return;
}

template <class T>
void print( T t ) {
  cout << t << endl;
  return;
}

template <class T, class ... R>
void print( T t, R ... r ) {
  cout << t << " ";
  print(r...);
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
