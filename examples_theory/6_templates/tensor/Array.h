#ifndef Array_h
#define Array_h

template <class T>
class Array {

 public:

  Array( unsigned int n );
  Array( const Array<T>& a );
  ~Array();

  Array<T>& operator=( const Array<T>& a );
  void resize( unsigned int n );

  unsigned int size() const;
  const
  T& operator[]( unsigned int i ) const;
  T& operator[]( unsigned int i );

  class OutOfRange {
   public:
    OutOfRange() {}
    ~OutOfRange() {}
  };
  bool checkRange( unsigned int i ) const;

  static bool debug;

 private:

  unsigned int eltn;
  T* cont;

  void copy( const Array<T>& a );

};

#include "Array.hpp"

#endif

