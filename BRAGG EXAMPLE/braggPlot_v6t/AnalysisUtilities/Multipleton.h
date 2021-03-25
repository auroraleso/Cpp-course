#ifndef Multipleton_H
#define Multipleton_H

#include <vector>

template <class T>
class Multipleton {

 public:

  // get the object instance
  static T* instance( unsigned int i, unsigned int n = 10 );
  static bool verbose;

 protected:

  // the object can be created only through a derived object
  // created in its turn by the "instance()" function
  Multipleton();
  virtual ~Multipleton();

  // retrieve the instance number
  unsigned int id() const;

 private:

  unsigned int instId;

};

#include "Multipleton.hpp"

#endif

