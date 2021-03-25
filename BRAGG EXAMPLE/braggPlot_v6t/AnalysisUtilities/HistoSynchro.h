#ifndef HistoSynchro_h
#define HistoSynchro_h

#include "TH1F.h"
//#include "TH2F.h"

#include <mutex>

template <class T>
class HistoSynchro: public T {

 public:

  template <class... S>
  HistoSynchro( S... x ): T( x... ) {}
  virtual ~HistoSynchro() {}

  template <class... S>
  int Fill( S... x ) {
    m.lock();
    int n = T::Fill( x... );
    m.unlock();
    return n;
  }

 private:

  std::mutex m;
  HistoSynchro           ( const HistoSynchro& x );
  HistoSynchro& operator=( const HistoSynchro& x );

};

class HistoSynchro1F: public HistoSynchro<TH1F> {
 public:
  template <class... S>
  HistoSynchro1F( S... x ): HistoSynchro<TH1F> ( x... ) {}
  int Fill( double x           )
      { return HistoSynchro<TH1F>::Fill( x    ); }
  int Fill( double x, double w )
      { return HistoSynchro<TH1F>::Fill( x, w ); }
};
/*
class HistoSynchro2F: public HistoSynchro<TH2F> {
 public:
  template <class... S>
  HistoSynchro2F( S... x ): HistoSynchro<TH1F> ( x... ) {}
  int Fill( double x, double y           )
      { return HistoSynchro<TH2F>::Fill( x, y    ); }
  int Fill( double x, double y, double w )
      { return HistoSynchro<TH2F>::Fill( x, y, w ); }
};
*/
#endif

