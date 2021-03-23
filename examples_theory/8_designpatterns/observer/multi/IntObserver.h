#ifndef IntObserver_H
#define IntObserver_H

#include "SimpleObserver.h"

#include <string>

class IntObserver: public SimpleObserver<int> {

 public:

  IntObserver( const std::string& n );
  ~IntObserver() override;

  void update( const int& x ) override;

 private:

  const std::string name;

};

#endif

