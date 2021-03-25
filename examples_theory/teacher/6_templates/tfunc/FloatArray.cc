#include "FloatArray.h"

#include <iostream>

using namespace std;

bool FloatArray::debug = false;

FloatArray::FloatArray( unsigned int n ):
  eltn( n ),
  cont( new float[eltn] ) {
  if ( debug ) cout << "created " << cont << endl;
}


FloatArray::FloatArray( const FloatArray& a ):
  cont( 0 ) {
  copy( a );
}


FloatArray::~FloatArray() {
  if ( debug ) cout << "delete " << cont << endl;
  delete[] cont;
}


FloatArray& FloatArray::operator=( const FloatArray& a ) {
  copy( a );
  return *this;
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
  return ( ( i >= 0 ) && ( i < eltn ) );
}


void FloatArray::copy( const FloatArray& a ) {
  if ( debug ) cout << "now copy " << cont << endl;
  if ( cont == a.cont ) return;
  delete[] cont;
  cont = new float[eltn = a.eltn];
  float* pr = a.cont + eltn;
  float* pl =   cont + eltn;
  while ( pl > cont ) *--pl = *--pr;
  return;
}

