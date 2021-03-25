#ifndef BaseA_h
#define BaseA_h

class BaseA {

 public:

  BaseA();
  virtual ~BaseA();

  virtual void f( int i );
  virtual void g();

 private:

  int n;

};

#endif

