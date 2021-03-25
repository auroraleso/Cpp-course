#ifndef Base_h
#define Base_h

#include <string>

class Base {

 public:

  Base( int i, const std::string& dname );
  virtual ~Base();

  virtual void f( int i );

  // function to be redefined  in IntermediateA
  // (and eventually IntermediateB and Derived)
  virtual void toBeRedefined();

 private:

  int n;

};

#endif

