#ifndef Tensor_h
#define Tensor_h

#include "Array.h"

template <unsigned int N, typename T> class Tensor {
  friend class Tensor<N+1,T>;
 public:
  typedef Tensor<N-1,T> subt;
  typedef Array<subt> type;
  typedef Array<unsigned int> dim;
  Tensor():
   A( 0 ),
   D( N ) {
     unsigned int i = N;
     while ( i-- ) D[i] = 0;
  }
  Tensor( const dim& n ):
   A( n[0] ),
   D( N ) {
     unsigned int i = N;
     while ( i-- ) D[i] = n[i];
     createSub( D, A );
  }
  const dim& size() const { return D; }
  const
  subt& operator[]( unsigned int i ) const { return A[i]; }
  subt& operator[]( unsigned int i )       { return A[i]; }
  const unsigned int dimension() const { return N; }
 private:
  type A;
  dim D;
  static void createSub( const dim& n, Array< Tensor<N-1,T> >& r ) {
    r.resize( n[0] );
    unsigned int d = n.size() - 1;
    dim m( d );
    unsigned int i = 0;
    for ( i = 0; i < d; ++i ) m[i] = n[i+1];
    for ( i = 0; i < n[0]; ++i ) Tensor<N-1,T>::createSub( m, r[i].A );
    return;
  }
};

template <typename T> class Tensor<1,T> {
  friend class Tensor<2,T>;
 public:
  typedef Array<T> type;
  typedef Array<unsigned int> dim;
  Tensor(): A( 0 ), D( 1 ) { D[0] = 0; }
  Tensor( dim n ): A( n[0] ), D( 1 ) { D[0] = n[0]; }
  const dim& size() { return D; }
  const
  T& operator[]( unsigned int i ) const { return A[i]; }
  T& operator[]( unsigned int i )       { return A[i]; }
 private:
  type A;
  dim D;
  static void createSub( const dim& n, type& r ) {
    r.resize( n[0] );
    return;
  }
};

#endif

