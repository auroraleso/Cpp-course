#include "ParticleMass.h"

#include "Event.h"
#include "MassMean.h"

#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;



double mass( const Event& e);


ParticleMass::ParticleMass() 
{
}

ParticleMass::~ParticleMass() {
}
void ParticleMass::pCreate( const string& nome, float min, float max ) {

  // create name for TH1F object
  const char* name = nome.c_str();

  // create TH1F and statistic objects and store their pointers
  Particle* part = new Particle;
  part-> nome = name;
  part->mean = new MassMean( min, max );
  part->h = new TH1F(name, name, 200, min-(max-min)*0.01, max+(max-min)*0.01 );
  pList.push_back( part );

  return;

}
 void ParticleMass::beginJob()
 {
	pList.reserve(2);
	pCreate( "K0", 0.495, 0.500 );
	pCreate("Lambda0", 1.115, 1.116 );
	return;
 }
 void ParticleMass::endJob()
 {
	 TDirectory* currentDir = gDirectory;
	 TFile* file = new TFile( "histogram.root", "RECREATE" );

	// open histogram file
	
       
        for ( Particle* p: pList ) {
			MassMean*  mean = p->mean;
			TH1F*      h = p->h;
		mean->compute();
		cout << mean->nEvents() << endl;
		cout << mean->Mmean()   << ' ' << mean->mRMS () << endl;
	h->Write();
	
		}
		file->Close();
	delete file;
	// restore working area
	currentDir->cd();
 }
 void ParticleMass::process(const Event& e)
 {
       
	for ( Particle* p: pList ){
		MassMean*  mean = p->mean;
		
		if(mean->add(e)){
			p->h->Fill(mass(e));
		}
	} 
	
	return;
 }

