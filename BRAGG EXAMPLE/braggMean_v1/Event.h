#ifndef Event_h
#define Event_h

extern int pointsMin;

struct Event {
  int evNumber; // event number
  int nPoints;  // number of points
  int* eLoss;   // array  of points
};

#endif

