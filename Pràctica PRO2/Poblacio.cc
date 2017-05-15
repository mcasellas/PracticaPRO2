#include "Poblacio.hh"

using namespace std;

Poblacio::Poblacio(){
    
}

Individu Poblacio::buscar_individu(string nom){
    
    map<string,Individu>::const_iterator it;
    
    it = poble.find(nom);
    
    return (*it).second;
    

}

bool Poblacio::comprovar_individu(string nom){
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        if ((*it).first == nom) return true;
    }
    
    return false;
}

void Poblacio::afegir_individu(string nom, const Individu& p){

    poble[nom] = p;
}

void Poblacio::escriure_arbre(string nom){ // Mirar estrucutra per amplada !!!!!!!
    
    queue<string> cua;
    
    buscar_descendents_cua(cua, buscar_individu(nom));
    
    cout << "  Nivell 0: " << nom << endl;;
    
    
    int nivell = 1;
    int parelles = 2;
    
    
    while (not cua.empty()){
        
        
        
        cout << "  Nivell " << nivell << ": ";
        
        int i = 0;
        
        while (i < parelles and not cua.empty()) {
            if (cua.front() != "$") cout << cua.front();
            if (i < parelles-1) cout << " ";
            cua.pop();
            ++i;
        }
        
        cout << endl;
        ++nivell;
        parelles *= 2;
        
        while (cua.front() == "$") cua.pop();
    }
    
    
}

void Poblacio::buscar_descendents_cua(queue<string>& cua, Individu ind){
    
    
    
    if (ind.consultar_pare() == "$") {
        cua.push("$");
        cua.push("$");
    }
    else {
        cua.push(ind.consultar_pare());
        cua.push(ind.consultar_mare());
        
        buscar_descendents_cua(cua, buscar_individu(ind.consultar_pare()));
        buscar_descendents_cua(cua, buscar_individu(ind.consultar_mare()));
    }
    
}

void Poblacio::completar_arbre(){
    
    Arbre<string> aparcial, acomplet;

    
    llegir_arbre_parcial(aparcial);
    
    escriure_arbre_string(aparcial);
    
    buscar_arbre_complet(acomplet, aparcial.arrel());
    
    cout << " "; 
    
    es_arbre_parcial(acomplet, aparcial);
    
    cout << endl;
    
}

void Poblacio::buscar_arbre_complet(Arbre<string>& arbre, string nom){
    
    Arbre<string> a1, a2;
    
    if (nom != "$"){
        Individu ind = buscar_individu(nom);
        
        
        
        buscar_arbre_complet(a1, ind.consultar_pare());
        buscar_arbre_complet(a2, ind.consultar_mare());
        arbre.plantar(nom, a1, a2);
    }
    
    else arbre.plantar(nom, a1, a2);

}

bool Poblacio::es_arbre_parcial(Arbre<string> acomplet, Arbre<string> aparcial){
    
    bool resultat = true;
    
    if (acomplet.es_buit()){
        resultat = false;
    }
    
    else {
        if (aparcial.es_buit()) { // PENSAR A COMPACTAR-HO
            cout << " " << acomplet.arrel();
        }
        
        else if (aparcial.arrel() == "$" and  acomplet.arrel() != "$"){
            cout << " *" << acomplet.arrel() << '*';
        }
        else if (aparcial.arrel() == acomplet.arrel()){
            cout << " " << acomplet.arrel();
        }
        
        else {
            resultat = false;
        }
        
        Arbre<string> ac1, ac2, ap1, ap2;
        
        acomplet.fills(ac1, ac2);
        if (not aparcial.es_buit()) aparcial.fills(ap1, ap2);
        resultat = es_arbre_parcial(ac1, ap1);
        resultat = es_arbre_parcial(ac2, ap2);
        
        
    }
    
    return resultat;
}

void Poblacio::llegir_arbre_parcial(Arbre<string>& a){
    
    Arbre<string> a1, a2;
    string nom;
    cin >> nom;
    if (nom != "$") {
        llegir_arbre_parcial(a1);
        llegir_arbre_parcial(a2);
        a.plantar(nom,a1,a2);
    }
    
    else a.plantar(nom, a1, a2);
}














void Poblacio::escriure_poblacio() const{
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        cout << "  " << (*it).first << " X" << (*it).second.consultar_sexe() << " (" << (*it).second.consultar_pare() << ',' << (*it).second.consultar_mare() << ')' << endl;
    }
    cout << endl;
}


void Poblacio::llegir_individu(Especie esp){
    
    Individu ind;
    string nom;

    cin >> nom;
    
    if (not comprovar_individu(nom)) {
        ind.llegir_individu(esp);

        afegir_individu(nom,ind);
        
        cout << "anadir_individuo " << nom << endl;
    }
    
    else cout << "  error" << endl;

}
