#ifndef A_h
#define A_h

class A {

 public:

  A();
  ~A();

  void f() const;

 private:

  int n;

  A           ( const A& a );
  A& operator=( const A& a );

};

#endif

