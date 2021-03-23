
// read integer numbers from the keyboard and write them onto the screen
// go on reading until interrupt

// read float numbers from the keyboard and write them onto the screen
// go on reading until interrupt

#include <iostream>

int main() {

  std::cout << "enter integer numbers" << std::endl;
  int i;
  while ( std::cin >> i ) std::cout << "got number " << i << std::endl;

  std::cin.clear();
/*
-----------------------------------CIN CLEAR AND IGNORE----------------------------------------------------
The cin.clear() clears the error flag on cin (so that future I/O operations will work correctly), 
and then cin.ignore(10000, '\n') skips to the next newline (to ignore anything else on the same line 
as the non-number so that it does not cause another parse failure). It will only skip up to 10000 characters, 
so the code is assuming the user will not put in a very long, invalid line.
*/


  std::cout << std::endl;
  std::cout << "enter float numbers" << std::endl;
  float x;
  while ( std::cin >> x ) std::cout << "got number " << x << std::endl;

  return 0;

}
