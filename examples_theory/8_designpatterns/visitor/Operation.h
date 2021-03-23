#ifndef Operation_h
#define Operation_h

#include <string>

class Triangle;
class Square;
class Rectangle;

class Operation {

 public:

  Operation( const std::string& name );
  virtual ~Operation();

  const std::string& name() const { return opName; }

  virtual void exec( const Triangle & t ) = 0;
  virtual void exec( const Square   & s ) = 0;
  virtual void exec( const Rectangle& r ) = 0;

  virtual float get() = 0;

 protected:

  const std::string opName;

};

#endif

