#ifndef EventSource_h
#define EventSource_h

#include <map>
#include <set>
#include <mutex>
#include <condition_variable>

class Event;

class EventSource {

 public:

  EventSource();
  // deleted copy constructor and assignment to prevent unadvertent copy
  EventSource           ( const EventSource& x ) = delete;
  EventSource& operator=( const EventSource& x ) = delete;

  virtual ~EventSource();

  // get events from source and store in a buffer with given size:
  // to be run by one single thread, the main or a separate one
  virtual void         runRead( unsigned int t );
  // send events in the buffer to observers giving a flag to identify thread:
  // to be run in multiple threads
  virtual unsigned int runSend( unsigned int t );

  // recover label identifying thread
  // declared static to allow calling it by objects not having access to
  // concrete event source
  static unsigned int thrId( const Event* ev );

 private:

  // flag to signal end of input, to be used by threads consuming 
  // events to avoid never ending wait at end of input
  enum class status { run, end };
  status runStatus;

  // get an event
  virtual const Event* get() = 0;

  // event buffer and corresponding mutex to avoid concurrent access
  std::set<const Event*> eBuf;
  std::mutex             mBuf;

  // get one event from buffer
  virtual const Event* next();

  // event-thread map and corresponding mutex to avoid concurrent access
  // declared static to be usable by "thrId" function (see above)
  static std::map<const Event*,unsigned int> tMap;
  static std::mutex                          mMap;

  // mutex and condition variable to make analysis threads wait
  // for events when buffer is empty
  std::mutex cms;
  std::condition_variable cvs;
  bool ready;

  // mutex and condition variable to make event source thread wait
  // when buffer if full
  std::mutex cmg;
  std::condition_variable cvg;
  bool evget;

};

#endif

