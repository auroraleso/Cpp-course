
// create the string "0abcdef" and write it onto the screen
// write onto the screen the fourth character of the string

// for each element in the string:
//  extract its ASCII code
//  copy the element on a character array
//  write on the screen ASCII code and character

// modify the fifth element of the array and write onto the screen
// truncate the array to four elements and write onto the screen


#include <iostream>

int main() {

  char s[10] = "0abcdef";
  std::cout << s << std::endl;

  std::cout << "ASCII codes" << std::endl;
  int i;
  for ( i = 0 ; i <=7 ; ++i ) {
    char c = s[i];
    int j = c;
    if ( j == 0 ) c = '*';
    std::cout << i << " " << j << " " << c << std::endl;
  }
  std::cout << std::endl;

  std::cout << "copy" << std::endl;
  char t[8];
  char* ps = s;
  char* pt = t;
  while ( ( *pt++ = *ps++ ) );
  // double parentheses to avoid warnings at compilation
  // equivalent to:
/*
  while ( *ps ) { // check the character is non-null
    *pt = *ps;    // copy the character
    ps++;         // go to next character in string s
    pt++;         // go to next character in string t
  } 
  *pt = *ps;      // copy the null character to terminate the string
*/

  std::cout << "s: " << s << std::endl;
  std::cout << "t: " << t << std::endl;
  if ( s == t ) std::cout << " s and t are equal"     << std::endl;
  else          std::cout << " s and t are different" << std::endl;
  std::cout << std::endl;

  std::cout << "modify" << std::endl;
  std::cout << t << std::endl;
  t[4] = 'T';
  std::cout << t << std::endl;
  t[4] = '\0';
  std::cout << t << std::endl;
  std::cout << std::endl;

  std::cout << "***********" << std::endl;
  std::cout << "s: " << s << std::endl;
  char* u = s; // here the string is NOT copied, only the address is copied

  u[3] = '.';
  std::cout << "u: " << u << std::endl;
  std::cout << "s: " << s << std::endl;


  return 0;

}

