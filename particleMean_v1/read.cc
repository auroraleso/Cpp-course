#include<iostream>
#include<fstream>
#include "structs.h"
//funzione di lettura
Event* read(std::ifstream &dati) 
{
    Event* e=new Event;
    int n;
   if (!(dati>>n)) return nullptr;
    
        dati >> e->numev;
        dati >> e->x >> e->y >> e->z;
        dati >> e->numPart;
        e->particelle= new Particle*[e->numPart];
        
        for(int i = 0; i < e->numPart; ++i)
        {
            Particle* p= new Particle;
            dati >> p->q >> p->px >> p->py >> p->pz; //leggo carica e momento a ciclo per tutte le particelle
            e->particelle[i]=p;
        }

        return e;
    
}
 
