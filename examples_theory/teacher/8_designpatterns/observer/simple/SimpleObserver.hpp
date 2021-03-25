//#include "SimpleObserver.h"
#include "SimpleDispatcher.h"

template <class T>
SimpleObserver<T>::SimpleObserver() {
  SimpleDispatcher<T>::subscribe( this );
}

template <class T>
SimpleObserver<T>::~SimpleObserver() {
  SimpleDispatcher<T>::unsubscribe( this );
}

