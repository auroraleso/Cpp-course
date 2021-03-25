#ifndef Event_h
#define Event_h

class Event {

 public:

  // create event with number "n"
  Event( int n );
  // deleted copy constructor and assignment to prevent unadvertent copy
  Event           ( const Event& x ) = delete;
  Event& operator=( const Event& x ) = delete;

  ~Event();

  // function to add a point
  void add( int energyLoss );

  // get event-specific informations:
  //   event number
  //   number of points in the event
  //   energy for point "i"
  int eventNumber() const;
  unsigned int dataSize() const;
  int energy( unsigned int i ) const;

  // get general informations
  static unsigned int maxSize();
  static unsigned int minSize();

 private:

  // shared variables to contain min and max number of points
  static unsigned int sMax;
  static unsigned int sMin;

  // event-specific informations:
  //   event number
  //   number of points in the event
  //   array with energies
  int evNumber;
  unsigned int nPoints;
  int* eLoss;

};

#endif

