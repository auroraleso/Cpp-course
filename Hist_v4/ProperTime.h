#ifndef ProperTime_h
#define ProperTime_h

#include "Event.h"
#include "Utilities.h"
#include "Constants.h"
#include "include/Singleton.h"
#include "include/LazyObserver.h"

class ProperTime: public Singleton<ProperTime>,
                    public LazyObserver<Event> {

  friend class Singleton<ProperTime>;

 public:

  // recompute informations for new event
 void update( const Event& ev ) override;

//return decay time
  double DecayTime();
 private:

  // private constructor and destructor for singleton
  ProperTime();
  // deleted copy constructor and assignment to prevent unadvertent copy
  ProperTime           ( const ProperTime& x ) = delete;
  ProperTime& operator=( const ProperTime& x ) = delete;

  // destructor
  ~ProperTime() override;



  //decay time
  double time;

};

#endif

