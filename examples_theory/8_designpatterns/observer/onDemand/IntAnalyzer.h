#ifndef IntAnalyzer_H
#define IntAnalyzer_H

#include "ActiveObserver.h"

class IntMultiplier;

#include <string>

class IntAnalyzer: public ActiveObserver<int> {

 public:

  IntAnalyzer();
  ~IntAnalyzer() override;

  void update( const int& x ) override;

 private:

  IntMultiplier* const im1;
  IntMultiplier* const im2;

};

#endif

