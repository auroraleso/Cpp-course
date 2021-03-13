#ifndef LifeTimeFit_h
#define LifeTimeFit_h
#include <vector>
class Event;

class LifeTimeFit {


 public:

  LifeTimeFit( double min, double max, double minTime, double maxTime, double minScan, double maxScan, double scanStep); // mass range
  ~LifeTimeFit();
unsigned int nEvents() const  ;   // return number of accepted events
  bool add( const Event& e );      // add data from a new event
  void compute();                   // empty
  double lifeTime();
  double lifeTimeError();
  

private:

  double min, max, minTime, maxTime, minScan, maxScan, scanStep, meanLifeTime, errorMeanLifeTime;
  std::vector<double> decaytimes;



 

};
#endif

