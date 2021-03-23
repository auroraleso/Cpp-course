#include <iostream>
#include <memory>

using namespace std;

class A {
 public:
  A()  { cout << "create A " << this << endl; }
  ~A() { cout << "delete A " << this << endl; }
  void p() { cout << "A::p " << this << endl; }
};

unique_ptr<A> create() {
  unique_ptr<A> a( new A );
  cout << "created: " << a.get() << endl;
  return a;
}

void f( unique_ptr<A>& a ) {
  cout << "start f: " << a.get() << endl;
  a->p();
//  unique_ptr<A> b = std::move( a );
  cout << "end   f: " << a.get() << endl;
  return;
}

void g( unique_ptr<A>& a ) {
  cout << "start g: " << a.get() << endl;
  f( a );
  cout << "end   g: " << a.get() << endl;
  return;
}

void h( unique_ptr<A>& a ) {
  cout << "start h: " << a.get() << endl;
  g( a );
  cout << "end   h: " << a.get() << endl;
  return;
}

int main() {
  unique_ptr<A> a = create();
  cout << "start m: " << endl;
  h( a );
  cout << "end   m: " << endl;
  return 0;
}

