#ifndef WrongS_h
#define WrongS_h

class WrongS {

 public:

  // get the object instance
  static WrongS* instance();

  // object functions
  void set( int i );
  int  get();

 private:

  int c;
  static WrongS* obj;

  // private constructor and destructor:
  // the object can be created only by the "instance()" function
  // and is destroyed at execution end
  WrongS();
  virtual ~WrongS();
  WrongS           ( const WrongS& x ) = delete;
  WrongS& operator=( const WrongS& x ) = delete;

};

#endif

