#ifndef ObjP_h
#define ObjP_h

class ObjP {

 public:

  // get the object instance
  static ObjP* instance();

  // object functions
  void set( int i );
  int  get();

 private:

  int c;

  // private constructor and destructor:
  // the object can be created only by the "instance()" function
  // and is destroyed at execution end
  ObjP();
  virtual ~ObjP();
  ObjP           ( const ObjP& x ) = delete;
  ObjP& operator=( const ObjP& x ) = delete;

};

#endif

