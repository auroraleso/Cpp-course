#ifndef IntMultiplier_H
#define IntMultiplier_H

#include "LazyObserver.h"

#include <string>

class IntMultiplier: public LazyObserver<int> {

 public:

  IntMultiplier( const std::string& n );
  ~IntMultiplier() override;

  void update( const int& x ) override;
  int get();

 private:

  const std::string name;
  int result;

};

#endif

