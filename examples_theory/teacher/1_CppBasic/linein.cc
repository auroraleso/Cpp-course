
// read from keyboard line by line

#include <iostream>

int main() {

  int maxLength = 1000;
  char line[maxLength];
  while ( std::cin.getline( line, maxLength ) )
    std::cout << "---> " << line << std::endl;

  return 0;

}


