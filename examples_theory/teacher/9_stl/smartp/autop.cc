#include <iostream>
#include <memory>

using namespace std;

class A {
 public:
  A()  { cout << "create A " << this << endl; }
  ~A() { cout << "delete A " << this << endl; }
  void p() { cout << "A::p " << this << endl; }
};

void f( auto_ptr<A> a ) {
  cout << "start f: " << a.get() << endl;
  a->p();
  cout << "end   f: " << a.get() << endl;
  return;
}

void g( auto_ptr<A> a ) {
  cout << "start g: " << a.get() << endl;
  f( a );
  cout << "end   g: " << a.get() << endl;
  return;
}

void h( auto_ptr<A> a ) {
  cout << "start h: " << a.get() << endl;
  g( a );
  cout << "end   h: " << a.get() << endl;
  return;
}

int main() {
  auto_ptr<A> a( new A );
  cout << "start m: " << a.get() << endl;
  h( a );
  cout << "end   m: " << a.get() << endl;
  cout << "============" << endl;
  auto_ptr<A> b( new A );
  cout << b.get() << endl;
  auto_ptr<A> c = b;
  cout << b.get() << " " << c.get() << endl;
  auto_ptr<A> d = c;
  cout << b.get() << " " << c.get() << " " << d.get() << endl;
  return 0;
}

