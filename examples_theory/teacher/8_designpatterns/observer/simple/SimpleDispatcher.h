#ifndef SimpleDispatcher_H
#define SimpleDispatcher_H

#include <set>

template <class T> class SimpleObserver;

template <class T>
class SimpleDispatcher {

  friend class SimpleObserver<T>;

 public:

  static void notify( const T& x );

 private:

  static void   subscribe( SimpleObserver<T>* obs );
  static void unsubscribe( SimpleObserver<T>* obs );

  SimpleDispatcher();
  ~SimpleDispatcher();

  static std::set<SimpleObserver<T>*>* observerList();

};

#include "SimpleDispatcher.hpp"

#endif

