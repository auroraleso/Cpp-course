#ifndef BGCalc_h
#define BGCalc_h

#include "util/include/ActiveObserver.h"
#include "AnalysisFramework/AnalysisSteering.h"

#include <vector>

class Event;
class TotalEnergy;

class BGCalc: public AnalysisSteering,
              public ActiveObserver<Event> {

 public:

  BGCalc( const AnalysisInfo* info );
  // deleted copy constructor and assignment to prevent unadvertent copy
  BGCalc           ( const BGCalc& x ) = delete;
  BGCalc& operator=( const BGCalc& x ) = delete;

  ~BGCalc() override;

  // function to be called at execution start
  void beginJob() override;
  // function to be called at execution end
  void   endJob() override;
  // function to be called for each event
  void update( const Event& ev ) override;

 private:

  // lazy observers:
  // each observer must be replicated to have a copy for each thread
  std::vector<TotalEnergy*> totalE;

  // min and max energy, min and max point, number of selected events
  int eMin;
  int eMax;
  int bMin;
  int bMax;
  std::vector<int> nEvt; // number of selected events in each thread

  // sum of energies and sum of square energies in each thread
  std::vector<float> bSum;
  std::vector<float> bSqr;

};

#endif

