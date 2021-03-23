#ifndef FixedSizeArray_h
#define FixedSizeArray_h

template <class T, unsigned int N>
class FixedSizeArray {

 public:

  FixedSizeArray();
  FixedSizeArray( const FixedSizeArray<T,N>& a );
  ~FixedSizeArray();

  FixedSizeArray<T,N>& operator=( const FixedSizeArray<T,N>& a );

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

  T* cont;

  void copy( const FixedSizeArray<T,N>& a );

};

#include "FixedSizeArray.hpp"

#endif

