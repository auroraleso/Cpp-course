#ifndef IntPower_H
#define IntPower_H

#include "SimpleObserver.h"

#include <string>

class IntPower: public SimpleObserver<int> {

 public:

  IntPower( int p );
  ~IntPower() override;

  void update( const int& x ) override;

 private:

  const int power;

};

#endif

