#include "Event.h"
const int Event::eventNumber ()
{
    return numev;
}
const float Event::getx()
{
    return x;
}
const float Event::gety()
{
    return y;
}
const float Event::getz()
{
    return z;
}

int Event::nParticles() const
{
    return numPart;
}
Event::pointpart Event::getParticle(int n) const
{
    if (n<maxNumPart)
        return particelle[n];
    else
        return nullptr;
    
}
//constructor 
Event::Event (int numev, double x, double y, double z)
{
    *particelle= new Particle[maxNumPart];
    this->x=x;
    this->y=y;
    this->z=z;
    this->numev=numev;
}
void Event::add (int q, double px, double py, double pz)
{
    if (numPart<maxNumPart)
    {  
        particelle[numPart]=new Particle();
        particelle[numPart]->px=px, 
        particelle[numPart]->py=py,
        particelle[numPart]->pz=pz, 
        particelle[numPart]->q=q;
        numPart++;
    }
}

//distruttore
Event::~Event()
{
    for (int i=0; i<numPart;++i)
    {
    delete[] particelle[i];
    }

}