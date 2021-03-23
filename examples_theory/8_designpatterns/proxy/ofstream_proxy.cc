#include "ofstream_proxy.h"

using namespace std; 

ofstream_proxy::ofstream_proxy( const char* name,
                                std::ios_base::openmode mode ):
 fName( name ),
 fMode( mode ),
 fStream( nullptr ) {
}


ofstream_proxy::~ofstream_proxy() {
  delete fStream;
}


ofstream& ofstream_proxy::operator*() {
  if ( fStream == nullptr ) fStream = new ofstream( fName.c_str(), fMode );
  return *fStream;
}


ofstream* ofstream_proxy::operator->() {
  if ( fStream == nullptr ) fStream = new ofstream( fName.c_str(), fMode );
  return fStream;
}

