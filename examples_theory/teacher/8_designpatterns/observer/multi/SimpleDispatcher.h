#ifndef SimpleDispatcher_H
#define SimpleDispatcher_H

#include <set>

template <class T> class SimpleObserver;

template <class T>
class SimpleDispatcher {

 public:

  void   subscribe( SimpleObserver<T>* obs );
  void unsubscribe( SimpleObserver<T>* obs );
  void notify( const T& x );

  SimpleDispatcher();
  ~SimpleDispatcher();

 private:

  std::set<SimpleObserver<T>*> observerList;

};

#include "SimpleDispatcher.hpp"

#endif

