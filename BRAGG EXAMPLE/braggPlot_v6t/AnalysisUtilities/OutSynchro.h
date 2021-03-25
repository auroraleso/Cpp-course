#ifndef OutSynchro_h
#define OutSynchro_h

#include <iostream>
#include <map>
#include <mutex>

class OutSynchro {

 public:

  static OutSynchro& get( std::ostream& os ) {
    static std::map<std::ostream*,OutSynchro*> om;
    std::ostream* op = &os;
    if ( om.find( op ) == om.end() )
         om.insert( make_pair( op, new OutSynchro( op ) ) );
    return *om[op];
  }
  ~OutSynchro();

  template<class T>
  OutSynchro& operator<<( const T& x ) {
    *oPtr << x;
    return *this;
  }

  typedef std::ostream& (*osm)( std::ostream& os );
  OutSynchro& operator<<( osm om ) {
    om( *oPtr );
    return *this;
  }

  typedef void (*lockManipulator)( OutSynchro& os );
  static void   lock( OutSynchro& os ) { os.wMutex.  lock(); }
  static void unlock( OutSynchro& os ) { os.wMutex.unlock(); }
  OutSynchro& operator<<( lockManipulator lm ) {
    lm( *this );
    return *this;
  }

 private:

  std::ostream* oPtr;
  std::mutex wMutex;

  OutSynchro( std::ostream* os ): oPtr( os ) {}

  OutSynchro()                                 = delete;
  OutSynchro           ( const OutSynchro& x ) = delete;
  OutSynchro& operator=( const OutSynchro& x ) = delete;

};

#endif

