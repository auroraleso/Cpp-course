#ifndef CheckPrime_H
#define CheckPrime_H

#include "LazyObserver.h"

#include <string>

class CheckPrime: public LazyObserver<int> {

 public:

  static CheckPrime* instance();
  ~CheckPrime() override;

  void update( const int& x ) override;
  bool isPrime();

 private:

  CheckPrime();
  bool primeFlag;

};

#endif

