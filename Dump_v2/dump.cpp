#include<iostream>
#include"structs.h"
void dump( const Event &e) 
{
  std::cout << e.numev 
            << std::endl 
            << e.x << ' ' <<  e.y << ' ' << e.z 
            << std::endl<< e.numPart 
            << std::endl;

  for (int i = 0; i < e.numPart; ++i) std::cout <<  e.particelle[i]->q << ' ' << e.particelle[i]->px << ' ' 
  <<  e.particelle[i]->py << " "<<e.particelle[i]->pz << std::endl;


}