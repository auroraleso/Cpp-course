#include <iostream>
#include <cmath>

//#define SELECTED GIOVANNI

#define ALDO     1
#define GIOVANNI 2
#define GIACOMO  3

int main() {

  std::cout << "file: " << __FILE__ << std::endl;
  std::cout << "line: " << __LINE__ << std::endl;
  std::cout << "date: " << __DATE__ << std::endl;
  std::cout << "time: " << __TIME__ << std::endl;
  std::cout << "c++ : " << __cplusplus << std::endl;

  std::cout << "At compilation time ";
#  if SELECTED == ALDO
  std::cout << "Aldo";
#elif SELECTED == GIOVANNI
  std::cout << "Giovanni";
#elif SELECTED == GIACOMO
  std::cout << "Giacomo";
#else
#error use -D SELECTED=ALDO or -D SELECTED=GIOVANNI or -D SELECTED=GIACOMO
#endif
  std::cout << " was selected" << std::endl;

  return 0;

}

