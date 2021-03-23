
// create an array of generic pointers and fill with 
// addresses of int and float variables
// print the content

#include <iostream>

void print( void* p, char t ) {
  switch ( t ) {
  case 'f':
    std::cout << *static_cast<float*>( p ) << std::endl; //converted void* to float*

          /*
                 ----------------------DEF OF STATIC CAST-------------------------

          This is the simplest type of cast which can be used. It is a compile time cast.
          It does things like implicit conversions between types (such as int to float, or pointer to void*),
          and it can also call explicit conversion functions (or implicit ones).
           */
    break;
  case 'i':
    std::cout << *static_cast<  int*>( p ) << std::endl;
    break;
  default:
    std::cout << "unknown type" << std::endl;
    break;
  }
}

int main() {

  void* p[10];
  char  t[10];

  p[0] = new float( 1.234 );
  t[0] = 'f';
  p[1] = new int  ( 456 );
  t[1] = 'i';
  p[2] = new float( 7.891 );
  t[2] = 'f';
  p[3] = new float( 6.543 );
  t[3] = 'f';
  p[4] = new int  ( 987 );
  t[4] = 'i';
  p[5] = new float( 1.098 );
  t[5] = 'f';
  p[6] = new int  ( 269 );
  t[6] = 'i';
  p[7] = new int  ( 854 );
  t[7] = 'i';
  p[8] = new int  ( 716 );
  t[8] = 'i';
  p[9] = new float( 3.92 );
  t[9] = 'f';

  int i;
  for ( i = 0; i < 10; ++i ) print( p[i], t[i] );

  return 0;

}

