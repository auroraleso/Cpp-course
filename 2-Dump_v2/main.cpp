#include<iostream>
#include<string>
#include<fstream>
#include "structs.h"

//firma funzione per leggere i dati dal file
Event* read(std::ifstream &file);

//firma funzione per scrivere i dati sul terminale
void dump(const Event &e);

//firma funzione per svuotare struct
void clear(const Event* e);

int main(){

    //lettura del nome del file di input
    std::cout << "Write file name (add .txt)" <<  std::endl;
     std::string nomeFile;
     std::cin >> nomeFile;

     Event const* evento=new Event;

     std::ifstream input;
    input.open(nomeFile);

    
    while(!input.eof()) {
       
        evento= read(input);
        dump(*evento);
        clear(evento);
    }
    

   
    input.close();
    return 0;
}