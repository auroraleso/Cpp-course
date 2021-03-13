#include<iostream>
#include"Event.h"

void dump( const Event &e)
{
  std::cout << e.eventNumber() 
            << std::endl 
            << e.getx() <<" "<<  e.gety() << " "<< e.getz() 
            << std::endl<<e.nParticles() 
            << std::endl;

  for (int i = 0; i < e.nParticles() ; ++i) 
  std::cout <<  e.getParticle(i)->q << " "<< e.getParticle(i)->px <<" "<<  e.getParticle(i)->py << " "
  <<e.getParticle(i)->pz<<std::endl;

  return;

}
