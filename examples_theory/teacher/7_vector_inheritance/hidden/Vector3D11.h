#ifndef Vector3D_h
#define Vector3D_h

#include "Vector2D.h"

// define a Vector3D as a Vector2D plus a z component
class Vector3D : public Vector2D {

 public:

  Vector3D();
  Vector3D( float x, float y, float z );
  ~Vector3D();

  // new function: get z component
  float getZ() const;
  // modified function: compute modulus with 3 components
  float mod() const;

  // new function, hiding function with the same name in Vector2D
  void transform( float f, float g, float h );

  // needed to allow calling the 2D transform function for 3D objects
  using Vector2D::transform;
  // if this declaration is omitted, the "Vector2D::transform" function
  // cannot be called for Vector3D objects, because it's hidden
  // by the "Vector3D::transform" function, even if the two functions 
  // have a different number of parameters.

 private:

  // z component
  float zv;

};

#endif
