#ifndef Shape_h
#define Shape_h

#include <string>

// generic geometric shape, with functions to compute area and perimeter
class Shape {

 public:

  Shape( const std::string& name );
  // destructor is declared virtual to allow the destruction of 
  // a specific object (triangle, square...) by calling "delete"
  // with a Shape pointer
  virtual ~Shape();

  // functions to compute are and perimeter are specific of
  // actual shapes (triangles, squares, rectangles),
  // area and perimeter are undefined for generic shapes,
  // and they're declared as "pure virtual functions"
  // no Shape object can be created, only derived objects
  // (re)implementing area and perimeter functions can be created
  virtual float area()      const = 0;
  virtual float perimeter() const = 0;

  // function to get shape name
  const std::string& name() const;
  // function to print name, area and perimeter
  void print() const;

 protected:

  const std::string m_name;

};

#endif

