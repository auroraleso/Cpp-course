#ifndef Shape_h
#define Shape_h

#include <string>

class Operation;

class Shape {

 public:

  Shape( const std::string& name );
  virtual ~Shape();

  const std::string& name() const { return m_name; }

  // execute operation
  virtual void exec( Operation& o ) const = 0;

 protected:

  const std::string m_name;

};

#endif

