
/* 
 -create a variable in the dynamic memory
 -create a dynamic array specifying dimensions from the keyboard
 -fill the array and write the content onto the screen
 -compute the sum of elements
 -free the memory*/

#include <iostream>
#include <cmath>

int main() {

  int i;
  std::cout<<"Insert an int: ";
  std::cin >> i;

  float* a = new float[i]; //dinamically allocate an array of i float elements 
  float* b = new float( 0 );

  int j;
  for ( j = 0; j < i; ++j ) {
    *b += ( a[j] = pow( j, 2 ) ); //filling the array as the number of position^2, summing the value to b
  }
  for ( j = 0; j < i; ++j ) {
    std::cout << j << " " << a[j] << std::endl; //print array
  }
  std::cout << *b << std::endl;

  delete[] a;
  delete b;

  return 0;

}

