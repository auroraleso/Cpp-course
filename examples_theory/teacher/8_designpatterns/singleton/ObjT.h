#ifndef ObjT_h
#define ObjT_h

#include "Singleton.h"

class ObjT: public Singleton<ObjT> {

 public:

  void set( int i );
  int  get();

 private:

  int c;

  friend class Singleton<ObjT>;
  ObjT();
  virtual ~ObjT();
  ObjT           ( const ObjT& x ) = delete;
  ObjT& operator=( const ObjT& x ) = delete;

};

#endif

