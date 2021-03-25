#ifndef Pluto_h
#define Pluto_h

class Pluto {

 public:

  Pluto( int i );
  ~Pluto();

  explicit operator int() const;

 private:

  int n;

};

#endif

