#include<fstream>
#include "Event.h"

Event* read(std::ifstream &dati) 
{
    int numev,numPart,n;
    double x,y,z;
    if (!(dati>>n)) return nullptr;
    
        dati >> numev;
        dati >> x >> y >> z;
        dati >> numPart;
        
        Event* e= new Event( numev,  x,  y,  z );
    
        for(int i = 0; i < numPart; ++i)
        {
            Particle* p= new Particle;
            dati >> p->q >> p->px >> p->py >> p->pz; //leggo carica e momento a ciclo per tutte le particelle
            e->add(p->q, p->px, p->py, p->pz);
        }
        return e;
    
    
}
