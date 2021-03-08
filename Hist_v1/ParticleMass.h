#ifndef ParticleMass_h
#define ParticleMass_h


#include "AnalysisSteering.h"
#include <vector>
#include <string>

class Event;
class MassMean;
class TH1F;

using namespace std;

class ParticleMass: public AnalysisSteering {

 public:

  ParticleMass();
  
  ParticleMass( const ParticleMass& x ) = delete;
  ParticleMass& operator=( const ParticleMass& x ) = delete;

  ~ParticleMass() override;

  
  void beginJob() override;
 
  void   endJob() override;

  void process( const Event& e ) override;

  

  private:
  struct Particle{
		string nome;  
		MassMean*   mean; 
		TH1F*       h; 
	};
	  vector<Particle*> pList;


	void pCreate( const string& nome, float min, float max );
};
#endif