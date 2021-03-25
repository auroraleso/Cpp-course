#include <iostream>
#include <memory>

using namespace std;

class A {
 public:
  A()  { cout << "create A " << this << endl; }
  ~A() { cout << "delete A " << this << endl; }
  void p() { cout << "A::p " << this << endl; }
};

void f( shared_ptr<A> a ) {
  cout << "start f: " << a.get() << ' ' << a.use_count() << endl;
  a->p();
  cout << "end   f: " << a.get() << ' ' << a.use_count() << endl;
  return;
}

void g( shared_ptr<A> a ) {
  cout << "start g: " << a.get() << ' ' << a.use_count() << endl;
  f( a );
  cout << "end   g: " << a.get() << ' ' << a.use_count() << endl;
  return;
}

void h( shared_ptr<A> a ) {
  cout << "start h: " << a.get() << ' ' << a.use_count() << endl;
  g( a );
  cout << "end   h: " << a.get() << ' ' << a.use_count() << endl;
  return;
}

int main() {
  shared_ptr<A> a( new A );
  cout << "start m: " << a.get() << ' ' << a.use_count() << endl;
  h( a );
  cout << "end   m: " << a.get() << ' ' << a.use_count() << endl;
  return 0;
}

