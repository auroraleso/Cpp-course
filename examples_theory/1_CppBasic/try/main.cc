
#include <iostream>
#include <fstream>
#include<string>
//writing on file
int main() {

  const char* p = "spritz";
  std::ofstream ofile( "out.txt" );
  ofile.write( p, 6 );

  return 0;

}


