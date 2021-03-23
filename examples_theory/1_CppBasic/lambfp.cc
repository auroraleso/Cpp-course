
// C++11 code
// loop over integers and apply a generic function to it
// use lambda functions

#include <iostream>

// function to print an integer and the result of a generic function
void print( int i, int (*f)( int ) ) {
  std::cout << i << " -> " << f( i ) << std::endl;
}

// test main program
int main() {

  int i;
  for ( i = 0; i < 10; ++i ) {
    print( i, []( int j ){ return j * j; } );     // square
    print( i, []( int j ){ return j * j * j; } ); // cube
  }

  return 0;

}


