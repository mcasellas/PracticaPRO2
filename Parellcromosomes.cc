/** @file Parellcromosomes.cc
 @brief Codi de la classe parellcromosomes
 */

#include "Parellcromosomes.hh"

using namespace std;

Parell_cromosomes::Parell_cromosomes(){
    
}

void Parell_cromosomes::creuament(Parell_cromosomes pare, Parell_cromosomes mare, int npare, int nmare, int k, int lo){
    
    int i;
    
    for (i = 0; i < lo; i++){ // Fins al punt de creuament
        if (i < k) {
            c1.push_back(mare.consultar_cromosoma(nmare)[i]);
            c2.push_back(pare.consultar_cromosoma(npare)[i]);
        }
        else {
            c1.push_back(pare.consultar_cromosoma(npare)[i]);
            c2.push_back(mare.consultar_cromosoma(nmare)[i]);
        }
    }
    
    if (i >= lo){ // Des del punt de creuament fins el final
        int aux = i;
        while (mare.consultar_cromosoma(nmare).size() != c1.size()){
            c1.push_back(mare.consultar_cromosoma(nmare)[i]);
            ++i;
        }
        i = aux;
        while (pare.consultar_cromosoma(npare).size() != c2.size()){
            c2.push_back(pare.consultar_cromosoma(npare)[i]);
            ++i;
        }
    }
}


void Parell_cromosomes::llegir_cromosomes_no_sexuals(int llargada_parell){
    int alel;
    for (int i = 0; i < llargada_parell; i++){
        cin >> alel;
        c1.push_back(alel);
    }
    
    for (int i = 0; i < llargada_parell; i++){
        cin >> alel;
        c2.push_back(alel);
    }
}

void Parell_cromosomes::llegir_cromosomes_sexuals(int primer, int segon, char sexe){
    int alel;
    for (int i = 0; i < primer; i++){
        cin >> alel;
        c1.push_back(alel);
    }
    
    if (sexe == 'X') segon = primer;
    
    for (int i = 0; i < segon; i++){
        cin >> alel;
        c2.push_back(alel);
    }
}

void Parell_cromosomes::escriure_cromosoma(int num) const {
    
    if (num == 1) for (int i = 0; i < c1.size(); i++) cout << " " << c1[i];
    
    else for (int i = 0; i < c2.size(); i++) cout << " " << c2[i];
    
    cout << endl;
}

vector<int> Parell_cromosomes::consultar_cromosoma(int num) const {
    if (num == 0) return c1;
    else return c2;
}

