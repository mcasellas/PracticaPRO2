#include "Parellcromosomes.hh"

using namespace std;

Parell_cromosomes::Parell_cromosomes(){
    
}

void Parell_cromosomes::creuament(Parell_cromosomes pare, Parell_cromosomes mare, int npare, int nmare, int k, int lo){
    vector<int> primerc;
    vector<int> segonc;
    
    vector<int> resultat1;
    vector<int> resultat2;
    
    primerc = mare.consultar_cromosoma(nmare);
    segonc = pare.consultar_cromosoma(npare);
    
    int i;
    
    for (i = 0; i < lo; i++){
        if (i < k) {
            resultat1.push_back(primerc[i]);
            resultat2.push_back(segonc[i]);
        }
        else {
                resultat1.push_back(segonc[i]);
                resultat2.push_back(primerc[i]);
        }
    }
    if (i >= lo){
        int aux = i;
        while (primerc.size() != resultat1.size()){
            resultat1.push_back(primerc[i]);
            ++i;
        }
        i = aux;
        while (segonc.size() != resultat2.size()){
            resultat2.push_back(segonc[i]);
            ++i;
        }
    }
    
    c1 = resultat1;
    c2 = resultat2;
    
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

void Parell_cromosomes::escriure_cromosoma(int num) const{
    if (num == 1) {
        for (int i = 0; i < c1.size(); i++) {
            cout << c1[i];
            if (i != c1.size()) cout << " ";
        }
        
        cout << endl;
    }
    else {
        for (int i = 0; i < c2.size(); i++) {
            cout << c2[i];
            if (i != c2.size()) cout << " ";
        }
        cout << endl;
    }
}

vector<int> Parell_cromosomes::consultar_cromosoma(int num) const{
    if (num == 0) return c1;
    else return c2;
}

