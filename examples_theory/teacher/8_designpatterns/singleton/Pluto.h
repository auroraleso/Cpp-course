#ifndef Pluto_h
#define Pluto_h

class Pluto {

 public:

  Pluto();
  Pluto           ( const Pluto& x ) = delete;
  Pluto& operator=( const Pluto& x ) = delete;

  virtual ~Pluto();

  void f();

};

#endif

