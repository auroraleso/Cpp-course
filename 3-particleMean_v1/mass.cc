#include<iostream>
#include "structs.h"
#include<cmath>
//firma funzione per calcolare energia particella
double particleEnergy(double px, double py, double pz, double m);
//firma funzione per calcolare massa invariante particella
double particleInvMass(double px, double py, double pz, double energy);
//compute mass
double mass (const Event& e)
{
    
    
    float sumpx=0,sumpy=0,sumpz=0;
    float sumEK0=0, sumELambda0=0;
    float massK0, massLambda0;
    int pos=0,neg=0;
    typedef const struct Particle* part ; 
    part p; 
    double m;
    for (int i=0; i<e.numPart;i++)
    {
        p=e.particelle[i];
        //according tp the charge sign, I increase the correct counter and set m to the correct mass to
        //compute sumELambda0
        if (p->q>=0)
        {
            m=0.938272;
            pos++;
        }
        if (p->q<0)
        {
            neg++;
            m=0.1395706;
        }
        sumpx+=p->px;
        sumpy+=p->py;
        sumpz+=p->pz;
        sumEK0+=particleEnergy(p->px,p->py,p->pz,0.1395706);
        sumELambda0+=particleEnergy(p->px,p->py,p->pz,m);

    }
    if (pos!=1 || neg!=1 )
    return -1;
    else
    {
        massK0=particleInvMass(sumpx,sumpy,sumpz,sumEK0);
        massLambda0=particleInvMass(sumpx,sumpy,sumpz,sumELambda0);
    }
    if (fabs(massK0-0.497611)< fabs(massLambda0-1.115683))
    return massK0;
    else
    return massLambda0;

}
