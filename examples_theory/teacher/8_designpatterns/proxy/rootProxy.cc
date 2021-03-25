// simple main program to test TFileProxy

#include "TFileProxy.h"
#include "TH1.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

void fill( const string& strn,
           const string& prob,
           const string& str1,
           const string& str2 ) {

  // extract generation parameters
  stringstream sstr;
  sstr.clear();
  sstr.str( str1 );
  float par1;
  sstr >> par1;
  sstr.clear();
  sstr.str( str2 );
  float par2;
  sstr >> par2;
  sstr.clear();
  sstr.str( strn );
  int n;
  sstr >> n;

  // build histogram name
  const string name = "hist_" + strn + "_" + str1 + "_" + str2;

  TH1F* hist;

  switch ( *prob.c_str() ) {
  case 'f':
    // random numbers with float distribution
    hist = new TH1F( name.c_str(), name.c_str(), 100, par1, par2 );
    while ( n-- ) {
      hist->Fill( par1 + random() * ( par2 - par1 ) / RAND_MAX );
    }
    break;
  case 'g':
    // random numbers with gaussian distribution
    hist = new TH1F( name.c_str(), name.c_str(), 100, par1 - ( 5 * par2 ),
                                                      par1 + ( 5 * par2 ) );
    while ( n-- ) {
      hist->Fill( par1 + ( par2 * sqrt( -log( random() * 1.0 / RAND_MAX ) ) *
                                  cos( M_PI * random() * 2.0 / RAND_MAX   ) ) );
    }
    break;
  }

  // save current working area
  TDirectory* currentDir = gDirectory;
  // open histogram file
  const string fn = prob + ".root";
  TFileProxy* file = new TFileProxy( fn.c_str(), "CREATE" );

  // write histogram
  hist->Write();

  // close file
  file->Close();
  delete file;
  // restore working area
  currentDir->cd();

  return;

}

int main( int argc, char* argv[] ) {

  // random numbers parameters
  string strn; // number of events
  string prob; // distribution: f (flat) or g (gaussian)
  string str1; // min value (flat) or mean value (gaussian)
  string str2; // max value (flat) or rms (gaussian)

  while ( cin >> strn >> prob >> str1 >> str2 ) fill( strn, prob, str1, str2 );

  return 0;

}

