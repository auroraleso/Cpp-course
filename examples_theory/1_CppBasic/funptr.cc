
// loop over integers and apply a generic function to it

#include <iostream>

// function computing the square of a number
int s( int i ) {
  return i * i;
}

// function computing the cube of a number
int c( int i ) {
  return i * i * i;
}

// function to print an integer and the result of a generic function
void print( int i, int (*f)( int ) ) {
  std::cout << i << " -> " << f( i ) << std::endl;
}

// test main program
int main() {

  int i;
  for ( i = 0; i < 10; ++i ) {
    print( i, s );
    print( i, c );
  }

  return 0;

}


