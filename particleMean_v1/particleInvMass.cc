#include<cmath>

double particleInvMass(double px, double py, double pz, double energy)
{
    //considering c=1;
    double m=sqrt(pow(energy,2)-(pow(py,2)+pow(pz,2)+pow(px,2)));
    return m;
}
