#include "EventReadFromFile.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// read data from file "name"
EventReadFromFile::EventReadFromFile( const string& nome ) {
  dati = new ifstream( nome );
}


EventReadFromFile::~EventReadFromFile() {
  delete dati;
}


// get an event
const Event* EventReadFromFile::get() {
  return readFile();
}


// read an event
const Event* EventReadFromFile::readFile() {
	
		int numev,numPart,n;
    double x,y,z;
     if (!(*dati>>n)) return nullptr;
    
        *dati >> numev;
        *dati >> x >> y >> z;
        *dati >> numPart;
        cout<<numPart<<endl;
        Event* e= new Event( numev,  x,  y,  z );
    
        for(int i = 0; i < numPart; ++i)
        {
            Particle* p= new Particle;
            *dati >> p->q >> p->px >> p->py >> p->pz; //leggo carica e momento a ciclo per tutte le particelle
            e->add(p->q, p->px, p->py, p->pz);
        }
        return e;
    
   

}

