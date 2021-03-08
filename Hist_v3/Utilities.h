#ifndef Utilities_h
#define Utilities_h

class Utilities{
	public:
	
	Utilities();
	// deleted copy constructor and assignment to prevent unadvertent copy
	Utilities           ( const Utilities& x ) = delete;
	Utilities& operator=( const Utilities& x ) = delete;
	
	~Utilities();
	
	// compute energy from momentum x,y,z components and invariant mass
	static double energy( double px, double py, double pz, double invMass);

   // compute invariant mass from momentum x,y,z components and energy
	static double invMass( double px, double py, double pz, double energy );
	
};

#endif