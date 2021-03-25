
// write onto the screen the executable name and the command line arguments

#include <iostream>
int main( int argc, char* argv[] ) {
  std::cout << argv[0]
            << " called with " << argc - 1 << " arguments";
  if ( argc > 1 ) std::cout << ":";
  int iarg;
  for ( iarg = 1; iarg < argc; ++iarg )
    std::cout << ( iarg > 1 ? ", " : " " ) << argv[iarg];
  std::cout << std::endl;
  return 0;
}
