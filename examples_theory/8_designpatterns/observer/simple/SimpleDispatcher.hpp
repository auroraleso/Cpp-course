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
  observerList()->insert( obs );
  return;
}

template <class T>
void SimpleDispatcher<T>::unsubscribe( SimpleObserver<T>* obs ) {
  observerList()->erase( obs );
  return;
}

template <class T>
void SimpleDispatcher<T>::notify( const T& x ) {
  static std::set<SimpleObserver<T>*>* ol = observerList();
  for ( auto& o: *ol ) o->update( x );
  return;
}

template <class T>
std::set<SimpleObserver<T>*>* SimpleDispatcher<T>::observerList() {
  static std::set<SimpleObserver<T>*>* ptr =
     new std::set<SimpleObserver<T>*>;
  return ptr;
}

