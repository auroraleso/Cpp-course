#include<iostream>

//creo le struct

//Particle con i dati su carica e momento di una particella
struct Particle {
int q;
float px;
float py;
float pz;
};
//Event con posizioni decay e numero particelle coinvolte
struct Event {
int numev;
float x;
float y;
float z;
int numPart;
Particle **particelle= new Particle*;
};