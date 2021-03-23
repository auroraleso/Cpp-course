//#include "FixedSizeArray.h"

#include <iostream>

template <class T, unsigned int N>
bool FixedSizeArray<T,N>::debug = false;

template <class T, unsigned int N>
FixedSizeArray<T,N>::FixedSizeArray():
  cont( new T[N] ) {
  if ( debug ) std::cout << "created " << cont << std::endl;
}


template <class T, unsigned int N>
FixedSizeArray<T,N>::FixedSizeArray( const FixedSizeArray<T,N>& a ):
  cont( new T[N] ) {
  copy( a );
}


template <class T, unsigned int N>
FixedSizeArray<T,N>::~FixedSizeArray() {
  if ( debug ) std::cout << "delete " << cont << std::endl;
  delete[] cont;
}


template <class T, unsigned int N>
FixedSizeArray<T,N>&
FixedSizeArray<T,N>::operator=( const FixedSizeArray<T,N>& a ) {
  copy( a );
  return *this;
}


template <class T, unsigned int N>
unsigned int FixedSizeArray<T,N>::size() const {
  return N;
}


template <class T, unsigned int N>
const
T& FixedSizeArray<T,N>::operator[]( unsigned int i ) const {
  if ( debug ) std::cout << "now access " << cont << " " << i << std::endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


template <class T, unsigned int N>
T& FixedSizeArray<T,N>::operator[]( unsigned int i ) {
  if ( debug ) std::cout << "now access " << cont << " " << i << std::endl;
  if ( !checkRange( i ) ) throw OutOfRange();
  return cont[i];
}


template <class T, unsigned int N>
bool FixedSizeArray<T,N>::checkRange( unsigned int i ) const {
  return ( ( i >= 0 ) && ( i < N ) );
}


template <class T, unsigned int N>
void FixedSizeArray<T,N>::copy( const FixedSizeArray<T,N>& a ) {
  if ( debug ) std::cout << "now copy " << cont << std::endl;
  if ( cont == a.cont ) return;
  T* pr = a.cont + N;
  T* pl =   cont + N;
  while ( pl > cont ) *--pl = *--pr;
  return;
}

