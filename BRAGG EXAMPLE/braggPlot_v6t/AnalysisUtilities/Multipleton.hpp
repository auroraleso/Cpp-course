// included by "Multipleton.h"
#include <iostream>

template <class T>
bool Multipleton<T>::verbose = false;

template <class T>
Multipleton<T>::Multipleton() {
  if ( verbose ) std::cout << "create Multipleton " << this << std::endl; 
}


template <class T>
Multipleton<T>::~Multipleton() {
  if ( verbose ) std::cout << "delete Multipleton " << this << std::endl; 
}


template <class T>
T* Multipleton<T>::instance( unsigned int i, unsigned int n ) {
  if ( verbose ) std::cout << "Multipleton::instance " << std::endl; 
  // the object list is created only once,
  // the first time "instance( i )" is called
  static std::vector<T*> objList( n, nullptr );
  // create new object if necessary
  if ( i >= objList.size() ) objList.resize( i + 1, nullptr );
  T*& objPtr = objList[i];
  if ( objPtr == nullptr ) {
    objPtr = new T;
    objPtr->instId = i;
  }
  return objPtr;
}


template <class T>
unsigned int Multipleton<T>::id() const {
  return instId;
}

