
// create and sort an array of 2D vectors

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Vector2D.h"

class Comp2D {
 public:
  bool operator()( const Vector2D* vl, const Vector2D* vr ) {
    float ql = pow( vl->getX(), 2 ) + pow( vl->getY(), 2 );
    float qr = pow( vr->getX(), 2 ) + pow( vr->getY(), 2 );
    return ql < qr;
  }
};

int main( int argc, char* argv[] ) {

  unsigned int n = 3;
  vector<Vector2D*> v( n );
  v[0] = new Vector2D( 12.34, -2.18 );
  v[1] = new Vector2D( -5.71, 13.66 );
  v[2] = new Vector2D(  8.59,  6.51 );

  vector<Vector2D*>::iterator it = v.begin();
  vector<Vector2D*>::iterator ie = v.end();
  Comp2D comp2D;
  sort( it, ie, comp2D );

  unsigned int i;
  for( i = 0; i < v.size(); ++i ) {
    const Vector2D& u = *v[i];
    cout << i << " " << u.getX() << " " << u.getY() << endl;
  }

  return 0;

}


