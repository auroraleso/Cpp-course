#include "FloatArray.h"

#include <iostream>
using namespace std;

bool FloatArray::debug = false;

FloatArray::FloatArray():
 eltn( 0 ),
 cont( nullptr ) {
  if ( debug ) cout << "created " << this << " ( " << cont
                    << " ) with " << eltn << " elements" << endl;
}


FloatArray::FloatArray( unsigned int n ):
 eltn( n ),
 cont( new float[eltn] ) {
  if ( debug ) cout << "created " << this << " ( " << cont
                    << " ) with " << eltn << " elements" << endl;
}


FloatArray::~FloatArray() {
  delete[] cont;
  if ( debug ) cout << "deleted " << this << " ( " << cont
                    << " ) with " << eltn << " elements" << endl;
}


unsigned int FloatArray::size() const {
  return eltn;
}


const
float& FloatArray::operator[]( unsigned int i ) const {
  if ( debug ) cout << "now access " << cont << " " << i << endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


float& FloatArray::operator[]( unsigned int i ) {
  if ( debug ) cout << "now access " << cont << " " << i << endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


bool FloatArray::checkRange( unsigned int i ) const {
  return ( i < eltn );
}

