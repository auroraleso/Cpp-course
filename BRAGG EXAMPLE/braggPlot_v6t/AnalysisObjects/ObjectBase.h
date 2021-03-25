#ifndef ObjectBase_h
#define ObjectBase_h

// class to interface LazyObserver with a threaded environment:
// having only one dispatcher, observers get events from all threads
// and must take care themselves to process only the ones assigned to them

// observers being singletons in the single-thread program version
// now must exist in multiple copies, so they're actually "multipletons"

#include "AnalysisFramework/EventSource.h"
#include "AnalysisUtilities/Multipleton.h"
#include "util/include/LazyObserver.h"
#include <iostream>

class Event;

template <class T>
class ObjectBase: public Multipleton<T>,
                  public LazyObserver<Event> {

  friend class Multipleton<T>;

 protected:

  ObjectBase() {}
  ~ObjectBase() override {}

 private:

  void lazyUpdate( const Event& ev ) override {
    // analyze only events having a thread label corresponding
    // to this instance sequential number
    if ( EventSource::thrId( &ev ) == Multipleton<T>::id() ) 
         LazyObserver<Event>::lazyUpdate( ev );
    return;
  }

  ObjectBase           ( const ObjectBase& x );
  ObjectBase& operator=( const ObjectBase& x );

};

#endif

