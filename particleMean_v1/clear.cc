#include<iostream>
#include "structs.h"
//funzione per svuotare struct
void clear (const Event* e)
{
  for (int i=0; i<e->numPart;++i)
  delete[] e->particelle[i];
  delete[] e->particelle;
  delete e;
  return ;
  
}