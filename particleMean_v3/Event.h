#ifndef Event_h
#define Event_h
#include<iostream>
#include <cstdlib>
#include<cmath>
#include<vector>

//Particle con i dati su carica e momento di una particella

 struct Particle {
int q;
float px;
float py;
float pz;
};

class Event {
    

    public:
    
   
typedef const Particle* pointpart;
    Event ( int id, double x, double y, double z);//constructor
    ~Event();
    void add ( int q, double px, double py, double pz);
     int eventNumber() const ;
     float getx() const , gety() const , getz() const ;
    

    pointpart getParticle(int n) const  ;
    
    int nParticles() const;

private:
    
    int numev;
    float x;
    float y;
    float z;
    std::vector<pointpart> particelle;

};
#endif