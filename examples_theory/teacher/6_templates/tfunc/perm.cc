template <class T>
void perm( T& x, T& y, T& z ) {
  T t = x;
  x = y;
  y = z;
  z = t;
//  cout << x.size() << " " << y.size() << " " << z.size() << endl;
  return;
}
