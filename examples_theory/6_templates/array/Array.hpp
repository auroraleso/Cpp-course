//#include "Array.h"

#include <iostream>

template <class T>
bool Array<T>::debug = false;

template <class T>
Array<T>::Array( unsigned int n ):
  eltn( n ),
  cont( new T[eltn] ) {
  if ( debug ) std::cout << "created " << cont << std::endl;
}


template <class T>
Array<T>::Array( const Array<T>& a ):
  cont( 0 ) {
  copy( a );
}


template <class T>
Array<T>::~Array() {
  if ( debug ) std::cout << "delete " << cont << std::endl;
  delete[] cont;
}


template <class T>
Array<T>& Array<T>::operator=( const Array<T>& a ) {
  copy( a );
  return *this;
}


template <class T>
unsigned int Array<T>::size() const {
  return eltn;
}


template <class T>
const
T& Array<T>::operator[]( unsigned int i ) const {
  if ( debug ) std::cout << "now access " << cont << " " << i << std::endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


template <class T>
T& Array<T>::operator[]( unsigned int i ) {
  if ( debug ) std::cout << "now access " << cont << " " << i << std::endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


template <class T>
bool Array<T>::checkRange( unsigned int i ) const {
  return ( ( i >= 0 ) && ( i < eltn ) );
}


template <class T>
void Array<T>::copy( const Array<T>& a ) {
  if ( debug ) std::cout << "now copy " << cont << std::endl;
  if ( cont == a.cont ) return;
  delete[] cont;
  cont = new T[eltn = a.eltn];
  T* pr = a.cont + eltn;
  T* pl =   cont + eltn;
  while ( pl > cont ) *--pl = *--pr;
  return;
}

