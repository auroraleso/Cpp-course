#include<iostream>
#include<cmath>
#include "structs.h"
//firma per funzione che calcola la massa 
double mass (const Event& e);

bool add (const Event& e, float min, float max, double &sumMass, double &sumSquares)
{
    double massa=mass(e);
    if (massa<max && massa>min)
    {
        sumMass+=massa;
        sumSquares+=pow(massa,2);
        return true;
    }
    else return false;
}
