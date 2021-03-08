#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include "structs.h"


//firma funzione per leggere i dati dal file
Event* read(std::ifstream &file);

//firma funzione per scrivere i dati sul terminale
void dump(const Event &e);

//firma funzione per svuotare struct
void clear(const Event* e);

//firma add function
bool add (const Event& e, float min, float max, double &sumMass, double &sumSquares);


int main(){
int acceptedEvent=0;
double sumMass=0, sumSquares=0, mean, rms;

    //asking name of input file
    std::cout << "Write file name (.txt)" << std::endl;
    std::string nomeFile;
    std::cin >> nomeFile;

     Event const* evento=new Event;
    
   
    std::ifstream input;
    input.open(nomeFile); //opens file

    
    while(!input.eof()) 
    {
        evento= read(input);
        if (add(*evento, 0.490, 0.505, sumMass, sumSquares)==true)
        {
            acceptedEvent++;
        }
       clear(evento);
    }
    mean=(sumMass/acceptedEvent);
    rms=sqrt((sumSquares-((acceptedEvent*pow(mean,2))))/acceptedEvent);
    std::cout<<"mean= "<<mean<<" rms= "<<rms<<std::endl;
    
    input.close(); //closes file
    return 0;
}