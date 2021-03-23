#ifndef ShapeFactory_h
#define ShapeFactory_h

#include <map>
#include <string>

class Shape;

class ShapeFactory {

 public:

  ShapeFactory();
  ~ShapeFactory();

  static Shape* create();
  static Shape* create( const char* line );

  static void registerShape( const Shape* shape );

 private:

  ShapeFactory           ( const ShapeFactory& x );
  ShapeFactory& operator=( const ShapeFactory& x );

  static std::map<std::string,const Shape*>* shapePrototype();

};

#endif

