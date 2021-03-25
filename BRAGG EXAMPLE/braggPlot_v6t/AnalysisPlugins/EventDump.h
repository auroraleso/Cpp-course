#ifndef EventDump_h
#define EventDump_h

#include "util/include/ActiveObserver.h"
#include "AnalysisFramework/AnalysisSteering.h"

class Event;

class EventDump: public AnalysisSteering,
                 public ActiveObserver<Event> {

 public:

  EventDump( const AnalysisInfo* info );
  ~EventDump() override;

  // function to be called at execution start
  void beginJob() override;
  // function to be called at execution end
  void   endJob() override;
  // function to be called for each event
  void update( const Event& ev ) override;

};

#endif

