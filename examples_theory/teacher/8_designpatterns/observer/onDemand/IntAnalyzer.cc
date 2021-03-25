#include "IntAnalyzer.h"
#include "IntMultiplier.h"
#include <iostream>

IntAnalyzer::IntAnalyzer():
  im1( new IntMultiplier( "Aldo"     ) ),
  im2( new IntMultiplier( "Giovanni" ) ) {
}

IntAnalyzer::~IntAnalyzer() {
}

void IntAnalyzer::update( const int& x ) {
  std::cout << " ************** new event: " << x
            << " **************" << std::endl;
  int r1 = im1->get();
  int r2 = im2->get();
  std::cout << r1 << " " << r2 << std::endl;
  return;
}

