#include <iostream>
#include <cmath>
using namespace std;

template <class T> class A {
 public:
  class C {
   public:
    C( T i ): k( i ) {}
    void g( T i ) { cout << "A::C::g() " << i + k << endl; }
   private:
    T k;
  };
  C* create( T i ) { return new C( i ); }
};

template <class T> class B {
 public:
  B( T i ): z( i ) {}
  void f( A<T>& p, T i ) {

    cout << "B::f( A& p ) " << i << endl;

    typename      //    A<T>::C is a class
    A<T>::C * c;  //    c is a pointer to A<T>
    c = p.create( i );
    c->g( z );

  }
 private:
  T z;
};

int main() {
  A<int> ai;
  B<int> bi( 3 );
  bi.f( ai, 2 );
  cout << "=============" << endl;
  A<double> ad;
  B<double> bd( M_PI );
  bd.f( ad, exp( 1.0 ) );
  return 0;
}


