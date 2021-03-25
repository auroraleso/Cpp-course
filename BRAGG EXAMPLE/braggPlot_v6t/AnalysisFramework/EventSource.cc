#include "AnalysisFramework/EventSource.h"
#include "AnalysisFramework/Event.h"
#include "util/include/Dispatcher.h"

#include <thread>
#include <iostream>

using namespace std;

// event-thread map and corresponding mutex to avoid concurrent access
map<const Event*,unsigned int> EventSource::tMap;
mutex                          EventSource::mMap;

EventSource::EventSource() {
  // set status to "run" to allow analysis threads to stay on wait
  runStatus = status::run;
}


EventSource::~EventSource() {
}


// get events from source and store them in a buffer with given size
// to be run by one single thread, the main or a separate one
void EventSource::runRead( unsigned int t ) {
  const Event* ev;
  unsigned int l;
  // set buffer flag to true to allow continuous loop until buffer is full
  evget = true;
  // go on reading events until end-of-file is reached
  while ( runStatus == status::run ) {
    // get current event buffer size
    mBuf.lock();
    l = eBuf.size();
    mBuf.unlock();
    // if the buffer is not full read one event
    if ( l < t ) {
      if ( ( ev = get() ) == nullptr ) {
        // at end of input set status to "end" to allow analysis 
        // threads stop looping
        runStatus = status::end;
        // awake threads waiting to avoid them being stuck
        // a lock_guard is an object locking the given mutex and
        // unlocking it when destroyed
        std::lock_guard<std::mutex> lg( cms );
        ready = true;
        cvs.notify_all();
        break;
      }
      // store event into buffer
      mBuf.lock();
      eBuf.insert( ev );
      mBuf.unlock();
      // set event flag to true
      std::lock_guard<std::mutex> lg( cms );
      ready = true;
      // notify analysis threads
      cvs.notify_all();
      continue;
    }
    else {
      // if the buffer is full set the flag to false, to avoid
      // wasting cpu time going on looping and checking continuously
      // for buffer size and instead wait until some event is actually
      // picked out from the buffer by some analysis thread
      std::lock_guard<std::mutex> lg( cmg );
      evget = false;
    }
    // notify analysis threads waiting for events, to avoid deadlocks
    cms.lock();
    ready = true;
    cms.unlock();
    cvs.notify_all();
    // until "evget" is false, that means the event buffer is currently
    // full, wait for notification:
    // the "wait" function does the following:
    // - releases the lock
    // - blocks the execution until notified
    // - when notified reacquires the lock and exits
    std::unique_lock<std::mutex> lk( cmg );
    while ( !evget ) cvg.wait( lk );
    // alternate expression:
    // "evget" is re-evaluated after receiving each notification,
    // and if found to be "false" again a new notification is waited;
    // the value is to be got by a function or a functor, i.e. an object
    // with a function-call operator (), so a lambda-function is used here:
    // the current class instance is captured with [this] and the
    // "evget" value is returned
//    if ( !evget ) cvg.wait( lk, [this]{ return evget; } );
  }
  return;
}


// send events in the buffer to observer giving a flag to identify thread
// to be run in multiple threads
unsigned int EventSource::runSend( unsigned int t ) {
  // set event flag to false to avoid continuous loop when looking events
  // in the buffer (see "next" function)
  ready = false;
  // set event counter
  unsigned int n = 0;
  const Event* ev;
  // pick up events from the buffer: "next" function takes care of
  // querying the buffer and wait, if necessary, for new events
  // to be filled
  while ( ( ev = next() ) != nullptr ) {
    // label this event with the sequential number of the thread
    mMap.lock();
    tMap[ev] = t;
    mMap.unlock();
    // increase the event count
    ++n;
    // dispatch event to observer: all observers get the event, so a
    // patch must be applied to avoid processing of the same event by
    // more than one thread, look at AnalysisObjects/ObjectBase.h for details
    Dispatcher<Event>::notify( *ev );
    // the "notify" functions calls in its turn the functions of the 
    // observers, so when it returns the processing of the event is 
    // completed
    // remove event from the label map after processing
    mMap.lock();
    tMap.erase( ev );
    mMap.unlock();
    // actually delete the event
    delete ev;
    // give back control to the process manager (not necessary)
    this_thread::yield();
  }
  // return the number of processed events
  return n;
}


// recover label identifying thread
unsigned int EventSource::thrId( const Event* ev ) {
  mMap.lock();
  static map<const Event*,unsigned int>& m = tMap;
  map<const Event*,unsigned int>::const_iterator iter = m.find( ev );
  map<const Event*,unsigned int>::const_iterator iend = m.end();
  unsigned int id = ( iter == iend ? -1 : iter->second );
  mMap.unlock();
  return id;
}


// get one event from buffer
const Event* EventSource::next() {
  const Event* ev = nullptr;
  // go on iterating until an event is found in the buffer
  while ( true ) {
    mBuf.lock();
    // check if the buffer does contain any event
    unsigned int l = eBuf.size();
    if ( l ) {
      // if the buffer is not empty pick up the first event
      // and remove it from the buffer
      ev = *eBuf.begin();
      eBuf.erase( ev );
      mBuf.unlock();
      // set buffer flag to true
      std::lock_guard<std::mutex> lg( cmg );
      evget = true;
      // notify source thread
      cvg.notify_all();
      // return the event
      return ev;
    }
    else {
      // if the buffer is empty set the flag to false, to avoid
      // wasting cpu time going on looping and checking continuously
      // for buffer size and instead wait until some event is actually
      // stored into the buffer, unless the end of input has been reached
      std::lock_guard<std::mutex> lg( cms );
      ready = ( runStatus == status::end );
    }
    mBuf.unlock();
    // exit the loop if the end of input has been reached
    if ( runStatus == status::end ) break;
    // notify source thread waiting for buffer space, to avoid deadlocks
    cmg.lock();
    evget = true;
    cmg.unlock();
    cvg.notify_all();
    // until "ready" is false, that means the event buffer is currently
    // empty but new events are to come, wait for notification:
    // the "wait" function does the following:
    // - releases the lock
    // - blocks the execution until notified
    // - when notified reacquires the lock and exits
    std::unique_lock<std::mutex> lk( cms );
    while ( !ready ) cvs.wait( lk );
    // alternate expression:
    // "ready" is re-evaluated after receiving each notification,
    // and if found to be "false" again a new notification is waited;
    // the value is to be got by a function or a functor, i.e. an object
    // with a function-call operator (), so a lambda-function is used here:
    // the current class instance is captured with [this] and the
    // "ready" value is returned
//    if ( !ready ) cvs.wait( lk, [this]{ return ready; } );
  }
  return nullptr;
}

