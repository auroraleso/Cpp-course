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

template <>
class A<int> {
 public:
  static int C;
};

int A<int>::C = 2;

template <class T> class B {
 public:
  B( T i ): z( i ) {}
  void f( A<T>& p, T i ) {

    cout << "B::f( A& p ) " << i << endl;

    int c = i * z;
    int r =       //    A<T>::C is an int
    A<T>::C * c;  //    A<T>::C * c is a product
    cout << r << endl;

  }
 private:
  T z;
};

int main() {
  A<int> ai;
  B<int> bi( 3 );
  bi.f( ai, 2 );
  cout << "=============" << endl;
//  A<double> ad;
//  B<double> bd( M_PI );
//  bd.f( ad, exp( 1.0 ) );
  return 0;
}


