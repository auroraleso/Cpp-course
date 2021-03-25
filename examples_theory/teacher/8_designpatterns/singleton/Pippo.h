#ifndef Pippo_h
#define Pippo_h

#include "Pluto.h"

class Pippo {

 public:

  Pippo();
  Pippo           ( const Pippo& x ) = delete;
  Pippo& operator=( const Pippo& x ) = delete;

  virtual ~Pippo();

  void f();

};

#endif

