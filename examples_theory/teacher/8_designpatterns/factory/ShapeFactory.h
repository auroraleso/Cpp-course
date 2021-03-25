#ifndef ShapeFactory_h
#define ShapeFactory_h

class Shape;

class ShapeFactory {

 public:

  ShapeFactory();
  ~ShapeFactory();

  static Shape* create();
  static Shape* create( const char* line );

 private:

  ShapeFactory           ( const ShapeFactory& x );
  ShapeFactory& operator=( const ShapeFactory& x );

};

#endif

