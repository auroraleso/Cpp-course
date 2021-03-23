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


FloatArray::FloatArray( const FloatArray& a ):
 cont( nullptr ) {
  copy( a );
  if ( debug ) cout << "copy created from "
                    << &a   << " ( " << a.eltn << ' ' << a.cont << " ) to "
                    << this << " ( " <<   eltn << ' ' <<   cont << " ) "
                    << endl;
}


FloatArray::~FloatArray() {
  delete[] cont;
  if ( debug ) cout << "deleted " << this << " ( " << cont
                    << " ) with " << eltn << " elements" << endl;
}


FloatArray& FloatArray::operator=( const FloatArray& a ) {
  copy( a );
  if ( debug ) cout << "copy assigned from "
                    << &a   << " ( " << a.eltn << ' ' << a.cont << " ) to "
                    << this << " ( " <<   eltn << ' ' <<   cont << " ) "
                    << endl;
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
  return ( i < eltn );
}


// the actual data container is copied element by element (deep copy)
void FloatArray::copy( const FloatArray& a ) {
  if ( debug ) cout << "now copy "
                    << &a   << " ( " << a.eltn << ' ' << a.cont << " ) to "
                    << this << " ( " <<   eltn << ' ' <<   cont << " ) "
                    << endl;
  if ( cont == a.cont ) return;
  delete[] cont;
  if ( debug ) cout << "released " << cont << endl;
  cont = new float[eltn = a.eltn];
  if ( debug ) cout << "allocated " << cont << endl;
  float* pr = a.cont + eltn;
  float* pl =   cont + eltn;
  while ( pl > cont ) *--pl = *--pr;
  return;
}

