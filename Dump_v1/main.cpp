#include<iostream>
#include<fstream>
#include<string>

//firma funzione per leggere i dati dal file
int read(std::ifstream &file, float &x, float &y, float &z, int *q, float *px, float *py, float *pz);

//firma funzione per scrivere i dati sul terminale
void dump(int n_event, int n_particles, float x, float y, float z, int *q, float *px, float *py, float *pz);

int main(){

    //lettura del nome del file di input
    std::cout << "Type file name (add .txt) and press enter" << std::endl;
    std::string file_name;
    std::cin >> file_name;

    //identifier
    int id;

    //numero di particelle
    int n_particles;

    //variabili posizione di decadimento
    float x, y, z;

    //array carica elettrica
    int q[10];

    //array momenti delle particelle 
    float px[10];
    float py[10];
    float pz[10];

    //apro il file
    std::ifstream input_file;
    input_file.open(file_name);

    //finche non arrivo alla fine del file:
    //1) leggo identifier del decadimenti
    //2) chiamo la funzione read che legge le cose importanti e restituisce il numero di particelle dopo il deca
    //3) chiamo la funzione dump che stampa a schermo i dati 
    while(!input_file.eof()) {
        input_file >> id;
        n_particles = read(input_file, x, y, z, q, px, py, pz);
        dump(id, n_particles, x, y, z, q, px, py, pz);
    }

    //chiudo il file
    input_file.close();
    return 0;
}