#ifndef LifeTimeFit_h
#define LifeTimeFit_h

class Event;

class LifeTimeFit {


 public:

  LifeTimeFit( double min, double max ); // mass range
  ~LifeTimeFit();
unsigned int nEvents() const  ;   // return number of accepted events
  bool add( const Event& e );      // add data from a new event
  void compute();                   // empty

  

private:

  double min, max;
  unsigned int acceptedev;	


 

};
#endif

