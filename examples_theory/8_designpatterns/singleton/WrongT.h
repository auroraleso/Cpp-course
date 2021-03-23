#ifndef WrongT_h
#define WrongT_h

class WrongS;

class WrongT {

 public:

  WrongT();
  virtual ~WrongT();

  void f();

 private:

  WrongS* singPtr;

  WrongT           ( const WrongT& x ) = delete;
  WrongT& operator=( const WrongT& x ) = delete;

};

#endif

