#ifndef SimpleObserver_H
#define SimpleObserver_H

template <class T>
class SimpleObserver {

 public:

  SimpleObserver();
  virtual ~SimpleObserver();

  virtual void update( const T& x ) = 0;

};

#include "SimpleObserver.hpp"

#endif

