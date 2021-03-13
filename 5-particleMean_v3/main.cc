#include<iostream>
#include<string>
#include<fstream>
#include "Event.h"
#include "MassMean.h"

using namespace std;
//firma funzione per leggere i dati dal file
Event* read(std::ifstream &file);

//firma funzione per scrivere i dati sul terminale
void dump(const Event &e);
int main()
{
MassMean K0(0.495, 0.500), L0(1.115, 1.116);

    cout << "Write file name (.txt): " ;
    string nomeFile;
    cin >> nomeFile;
    const Event* evento;
    
    ifstream input;
    input.open(nomeFile);
    
    while(!input.eof()) 
    {
        evento= read(input);
       // dump(*evento);
       
        K0.add(*evento);
        L0.add(*evento);
      
        delete evento; //chiama il distruttore dell'evento

        K0.compute( );
        L0.compute( );
    }
        
    cout<<"media K0: "<<K0.Mmean()<<endl;
    cout<<"media L0: "<<L0.Mmean()<<endl;
    cout<<"rms K0: "<<K0.mRMS()<<endl;
    cout<<"rms L0: "<<L0.mRMS()<<endl;
  
    input.close();
    return 0;
    
}
