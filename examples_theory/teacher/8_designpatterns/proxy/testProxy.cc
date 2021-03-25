#include "ofstream_proxy.h"

using namespace std;

void checkDiv( int i, int j, ofstream_proxy& osp ) {
  if ( !( i % j ) ) *osp << i << " is divisible by " << j << endl;
}

int main() {
  int i;
  ofstream_proxy osp( "factors" );
//  ofstream_proxy osp( "factors", ios_base::app );
  cin >> i;
  checkDiv( i,  2, osp );
  checkDiv( i,  3, osp );
  checkDiv( i,  5, osp );
  checkDiv( i,  7, osp );
  checkDiv( i, 11, osp );
  checkDiv( i, 13, osp );
  checkDiv( i, 17, osp );
  checkDiv( i, 19, osp );
  return 0;
}

