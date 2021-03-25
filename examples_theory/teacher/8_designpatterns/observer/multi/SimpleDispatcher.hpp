//#include "SimpleDispatcher.h"
#include "SimpleObserver.h"


template <class T>
SimpleDispatcher<T>::SimpleDispatcher() {
}

template <class T>
SimpleDispatcher<T>::~SimpleDispatcher() {
}

template <class T>
void SimpleDispatcher<T>::subscribe( SimpleObserver<T>* obs ) {
  observerList.insert( obs );
  return;
}

template <class T>
void SimpleDispatcher<T>::unsubscribe( SimpleObserver<T>* obs ) {
  observerList.erase( obs );
  return;
}

template <class T>
void SimpleDispatcher<T>::notify( const T& x ) {
  for ( auto& a: observerList ) a->update( x );
  return;
}

