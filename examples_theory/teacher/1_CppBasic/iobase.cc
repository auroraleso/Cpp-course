
#include <iostream>
#include <fstream>
//writing on file
int main() {

  const char* p = "fluttuazioni statistiche non banali cit.";
  std::ofstream ofile( "out.txt" );
  ofile.write( p, 10 );

  return 0;

}


