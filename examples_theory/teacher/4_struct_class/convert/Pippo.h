#ifndef Pippo_h
#define Pippo_h

class Pippo {

 public:

  Pippo( int i );
  ~Pippo();

  operator int() const;

 private:

  int n;

};

#endif

