#include "EventReadFromFile.h"

#include "Event.h"

#include <fstream>
#include <string>

using namespace std;

// read data from file "name"
EventReadFromFile::EventReadFromFile( const string& nome ) {
  file = new ifstream( nome );
}


EventReadFromFile::~EventReadFromFile() {
  delete file;
}


// get an event
const Event* EventReadFromFile::get() {
  return readFile();
}


// read an event
const Event* EventReadFromFile::readFile() {

	// event pointer and number
	Event* e;
	int n;
	
		if( !( *file >> n ) ) return nullptr;
	
	double x, y, z;
	*file >> x;
	*file >> y;
	*file >> z;
	
	// pass event number and coordinates to the constructor
	e = new Event( n, x, y, z );

	// read number of particles
	*file >> n;
	
	// read particles data
	int q;
	double px, py, pz;
	for (int i = 0; i < n; ++i){
		*file >> q;
		*file >> px;
		*file >> py;
		*file >> pz;
		e->add( q, px, py, pz );
	}
	

	return e;

}

