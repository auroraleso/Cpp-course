#ifndef Event_h
#define Event_h
#include<cmath>
#include<vector>
using namespace std;

//Particle con i dati su carica e momento di una particella
struct Particle {
int q;
float px;
float py;
float pz;
};

class Event {
    private:
    int numev;
    float x;
    float y;
    float z;
    int numPart=0;
    int const maxNumPart=10;
    Particle** particelle= new Particle*;

    public:
    Event ( int id, double x, double y, double z);//constructor
    ~Event();
    void add ( int q, double px, double py, double pz);
    const int eventNumber();
    const float getx(), gety(), getz();
    typedef  Particle* pointpart;
    int nParticles() const;
    pointpart getParticle(int n) const ;

};



#endif