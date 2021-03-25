#include<cmath>

double particleEnergy(double px, double py, double pz, double m)
{
    //considering c=1;
    double energy=sqrt(pow(px,2)+pow(py,2)+pow(pz,2)+pow(m,2));
    return energy;
}
