#ifndef ObjS_h
#define ObjS_h

class ObjS {

 public:

  // get the object instance
  static ObjS* instance();

  // object functions
  void set( int i );
  int  get();

 private:

  int c;

  // private constructor and destructor:
  // the object can be created only by the "instance()" function
  // and is destroyed at execution end
  ObjS();
  virtual ~ObjS();
  ObjS           ( const ObjS& x ) = delete;
  ObjS& operator=( const ObjS& x ) = delete;

};

#endif

