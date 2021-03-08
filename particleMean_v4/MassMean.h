#ifndef MassMean_h
#define MassMean_h

class Event;

class MassMean {


 public:

  MassMean( double min, double max ); // mass range
  ~MassMean();
unsigned int nEvents() const  ;   // return number of accepted events
  double Mmean() const;             // return mean mass
  double mRMS() const;              // return rms  mass
  void add( const Event& e );      // add data from a new event
  void compute();                   // compute mean and rms

  

private:

  double min, max;
  unsigned int acceptedev;	
  double mean,  rms, massum, squaresum;	

 

};
#endif

