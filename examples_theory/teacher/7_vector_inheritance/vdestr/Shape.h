#ifndef Shape_h
#define Shape_h

// generic geometric shape, with functions to compute area and perimeter
class Shape {

 public:

  Shape();
  // destructor is declared virtual to allow the destruction of 
  // a specific object (triangle, square...) by calling "delete"
  // with a Shape pointer
  virtual ~Shape();

  // functions to compute are and perimeter are specific of
  // actual shapes (triangles, squares, rectangles)
  virtual float area()      const;
  virtual float perimeter() const;

  // function to print area and perimeter
  void print() const;

};

#endif

