#include "Event.h"

void clear( const Event* ev ) {

  // delete the array
  delete[] ev->eLoss;

  // delete the event
  delete ev;

  return;

}

