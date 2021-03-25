#ifndef Shape_h
#define Shape_h

// generic geometric shape, with functions to compute area and perimeter
class Shape {

 public:

  Shape();
  virtual ~Shape();

  // functions to compute are and perimeter are specific of
  // actual shapes (triangles, squares, rectangles)
  virtual float area()      const;
  virtual float perimeter() const;

};

#endif

