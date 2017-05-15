#include "Individu.hh"

using namespace std;

Individu::Individu(){
    
}

void Individu::reproduir(Individu indpare, Individu indmare, string npare, string nmare, string nfill, const Especie& esp){
    
        int cromo_mare, cromo_pare, punt_tall;
        
        for (int i = 0; i <= esp.consultar_n(); i++) { // Cromosoma a cromosoma
  
            cin >> cromo_mare >> cromo_pare >> punt_tall;
            
            if (i == 0) {
                if (cromo_pare == 1) sexe = 'Y';
                else sexe = 'X';
            }
            
            Parell_cromosomes par_result;
            
      
            
            par_result.creuament(indpare.consultar_parell_cromosomes(i), indmare.consultar_parell_cromosomes(i), cromo_pare, cromo_mare, punt_tall, esp.consultar_ln(i));
            
            adn.push_back(par_result);
        
    }

    pare = npare;
    mare = nmare;
}


char Individu::consultar_sexe() const{
    return sexe;
}


Parell_cromosomes Individu::consultar_parell_cromosomes(int i){
    return adn[i];
}


string Individu::consultar_pare() const{
    return pare;
}


string Individu::consultar_mare() const{
    return mare;
}

void Individu::escriure_genotip(Especie esp) const{
    for (int i = 0; i < adn.size(); i++) {
        if (i == 0){ // Escrivim primer els cromosomes sexuals
            cout << "  X: ";
            adn[i].escriure_cromosoma(1);
        
            cout << "  Y: ";
            adn[i].escriure_cromosoma(2);
        }
        
        else {
            cout << "  " << i << ".1: ";
            adn[i].escriure_cromosoma(1);
            
            cout << "  " << i << ".2: ";
            adn[i].escriure_cromosoma(2);
        }
    }
    cout << endl;
}


void Individu::llegir_individu(Especie esp){
    
    cin >> sexe;
    
    
    

    // Cromosomes sexuals
        Parell_cromosomes parell;
        parell.llegir_cromosomes_sexuals(esp.consultar_lx(), esp.consultar_ly(), sexe);
        adn.push_back(parell);
    
    
    // Cromosomes no sexuals
    for (int i = 1; i <= esp.consultar_n(); i++){
        Parell_cromosomes parell;
        parell.llegir_cromosomes_no_sexuals(esp.consultar_ln(i));
        adn.push_back(parell);
    }
    
    mare = "$";
    pare = "$";
}
