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

 private:

  // z component
  float zv;

};

#endif
