#include "Event.h"
 int Event::eventNumber () const
{
    return numev;
}
 float Event::getx() const
{
    return x;
}
 float Event::gety() const
{
    return y;
}
 float Event::getz() const
{
    return z;
}

Event::pointpart Event::getParticle(int n) const
{
        return particelle.at(n);
}
//constructor 
Event::Event (int numev, double x, double y, double z)
{

    particelle.reserve(10);
    this->x=x;
    this->y=y;
    this->z=z;
    this->numev=numev;
}
void Event::add (int q, double px, double py, double pz)
{
        Particle* p= new Particle ;
        p->q=q, p->px=px, p->py=py, p->pz=pz;
        particelle.push_back(p);
}
int Event::nParticles() const
{
    return particelle.size();
}
//distruttore
Event::~Event()
{
    for( unsigned int i = 0; i < particelle.size(); ++i ){
	delete particelle[i];
}
}


