#ifndef ofstream_proxy_h
#define ofstream_proxy_h

#include <iostream>
#include <fstream>
#include <string>

class ofstream_proxy {

 public:

  // constructor
  ofstream_proxy( const char* name,
                  std::ios_base::openmode mode = std::ios_base::trunc );

  // deleted copy constructor and assignment to prevent unadvertent copy
  ofstream_proxy           ( const ofstream_proxy& x ) = delete;
  ofstream_proxy& operator=( const ofstream_proxy& x ) = delete;

  // destructor
  virtual ~ofstream_proxy();

  std::ofstream& operator*();
  std::ofstream* operator->();

 private:

  const
  std::string             fName;
  const
  std::ios_base::openmode fMode;
  std::ofstream*          fStream;

};

#endif

