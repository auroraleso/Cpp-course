#ifndef Base_h
#define Base_h

class Base {

 public:

  Base( int i );
  virtual ~Base();

  virtual void f( int i );

 private:

  int n;

};

#endif

