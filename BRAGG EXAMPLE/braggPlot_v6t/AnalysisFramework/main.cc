#include <vector>
#include <iostream>
#include <future>

#include "AnalysisFramework/EventSource.h"
#include "AnalysisFramework/SourceFactory.h"
#include "AnalysisFramework/AnalysisInfo.h"
#include "AnalysisFramework/AnalysisFactory.h"
#include "util/include/Dispatcher.h"

using namespace std;

int main( int argc, char* argv[] ) {

  // store command line parameters
  AnalysisInfo* info = new AnalysisInfo( argc, argv );

  // create data source
  EventSource* es = SourceFactory::create( info );

  // create a list of analyzers
  AnalysisFactory::create( info );

  // initialize all analyzers
  Dispatcher<AnalysisInfo::AnalysisStatus>::notify( AnalysisInfo::begin );

  // launch threads processing events:
  // they will stay on wait until the event buffer starts to be filled;
  // each thread runs a function picking events from the buffer and 
  // returning at the end the number of processed events; the function
  // simply runs "runSend" for the given event source, giving as 
  // argument the sequential number of the thread and returning the result.
  unsigned int i;
  unsigned int m = info->nThreads();
  vector<future<unsigned int>*> tList( m );
  for ( i = 0; i < m; ++i ) tList[i] =
                            new future<unsigned int>( async( launch::async,
                []( EventSource* s, unsigned int n ){ return s->runSend( n ); },
                                                      es, i ) );
  cout << m << " threads started" << endl;

  // launch an additional thread to read events and fill the buffer,
  // up to a max size of twice the number of analyzer threads
  thread tRead( []( EventSource* s, unsigned int n ){ s->runRead( n ); },
                                                      es, 2 * m );

  // all threads are running, so to print the number of events processed 
  // by threads as and when they complete some loop-and-wait mechanism
  // is necessary; look at EventSource.h and EventSource.cc for details

  // print number of events processed by each thread:
  // go on looping over all threads, until all of them have been accounted for
  unsigned int s = 0;          // total number of events
  unsigned int w = m;          // number of thread to wait for
  // loop until there are threads to wait
  while ( w ) {
    for ( i = 0; i < m; ++i ) {
      auto& tPtr = tList[i];
      // skip thread already accounted for
      if ( tPtr == nullptr ) continue;
      // skip thread still running
      if ( tPtr->wait_for( std::chrono::milliseconds( 1 ) ) !=
           future_status::ready ) continue;
      // get, print and sum number of events
      unsigned int c = tPtr->get();
      cout << c << " events read in thread " << i << endl;
      s += c;
      // decrease number of threads to wait
      --w;
      // delete this thread
      delete tPtr;
      tPtr = nullptr;
    }
    // before iterating again it would be much better (really much better)
    // waiting for some thread actually to complete, in place of wasting
    // cpu time to loop over and over them checking continuously; this is
    // done here to limit the program complexity
    // alternatively a call to "sleep" could be inserted to introduce
    // a simple delay before next iteration; this is not done here because
    // the total execution time with the given input is shorter than any
    // reasonable explicit time lapse (e.g. 1 second)
  }
  cout << s << " total events" << endl;

  // close thread reading events
  tRead.join();

  // finalize all analyzers
  Dispatcher<AnalysisInfo::AnalysisStatus>::notify( AnalysisInfo::end );

  return 0;

}

