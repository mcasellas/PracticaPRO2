/** @file Poblacio.cc
 @brief Codi de la classe població
 */

#include "Poblacio.hh"

using namespace std;

Poblacio::Poblacio(){
    
}

Individu Poblacio::consultar_individu(string nom){
    
    map<string,Individu>::const_iterator it;
    
    it = poble.find(nom);
    
    return (*it).second;
    
}

bool Poblacio::existeix_individu(string nom){
    
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        if ((*it).first == nom) return true;
    }
    
    return false;
}

void Poblacio::afegir_individu(string nom, const Individu& p){
    poble[nom] = p;
}



void Poblacio::reproduir(string pare, string mare, string fill, Especie esp){
    
    if (comprovar_reproduccio(pare, mare, fill)){
        
    Individu ind;
    
    ind.reproduir(consultar_individu(pare), consultar_individu(mare), pare, mare, esp);
    
    afegir_individu(fill, ind);
    }
}


void Poblacio::escriure_arbre_genealogic(string nom){
    cout << "escribir_arbol_genealogico " << nom << endl;
    
    if (existeix_individu(nom)){
        Arbre<string> complet;
        
        queue<string> cua_nom;
        queue<int> cua_niv;
        
        cua_nom.push(nom);
        
        cua_niv.push(0);
        
        int nivell = -1;
        
        while (not cua_nom.empty()) {
            
            if (consultar_individu(cua_nom.front()).consultar_pare() != "$") {
                cua_nom.push(consultar_individu(cua_nom.front()).consultar_pare());
                cua_niv.push(cua_niv.front()+1);
                
                cua_nom.push(consultar_individu(cua_nom.front()).consultar_mare());
                cua_niv.push(cua_niv.front()+1);
            }
            
            if (nivell != cua_niv.front()) {
                if (nivell != -1) cout << endl;
                nivell = cua_niv.front();
                cout << "  Nivel " << nivell << ':';
            }
            
            cout << " " << cua_nom.front();
            
            cua_nom.pop();
            cua_niv.pop();
        }
        
        cout << endl;

        
    }
    
    else cout << "  error" << endl;
}

void Poblacio::completar_arbre(){
    
    Arbre<string> aparcial, acomplet;
    
    llegir_arbre_parcial(aparcial);
    
    cout << "completar_arbol_genealogico " << aparcial.arrel() << endl;
    
    bool valid = existeix_individu(aparcial.arrel());
    
    if (valid) {
    
        buscar_arbre(acomplet, aparcial.arrel());
        
        vector<string> resultat;
        
        bool parcial = es_arbre_parcial(resultat, acomplet, aparcial);
        
        if (parcial) {
            cout << "  ";
            
            for (int i = 0; i < resultat.size(); i++){
                cout << resultat[i];
                if (i != resultat.size()-1) cout << ' ';
            }
            
            cout << endl;
            
        }
        
        else valid = false;
    
    }
    
    if (not valid) cout << "  no es arbol parcial" << endl;
    
    
}




void Poblacio::escriure_poblacio() const{
    
    cout << "escribir_poblacion" << endl;
    
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        cout << "  " << (*it).first << " X" << (*it).second.consultar_sexe() << " (" << (*it).second.consultar_pare() << ',' << (*it).second.consultar_mare() << ')' << endl;
    }

}


void Poblacio::llegir(Especie esp){
    
    string nom;

    cin >> nom;
    
    cout << "anadir_individuo " << nom << endl;
    
    if (not existeix_individu(nom)) {
        Individu ind;
        ind.llegir_individu(esp);

        afegir_individu(nom,ind);
    }
    
    else cout << "  error" << endl;

}

void Poblacio::llegir_inicials(Especie esp){
    int ninicials;
    
    cin >> ninicials;
    
    for (int i = 0; i < ninicials; i++) {
        Individu ind;
        string nom;
        
        cin >> nom;
        
        ind.llegir_individu(esp);
        
        afegir_individu(nom,ind);
    }
}



//Privades

bool Poblacio::buscar_ascendent(Individu ind, string nom){
    
    bool resultat = false;
    
    if (ind.consultar_mare() == nom or ind.consultar_pare() == nom) resultat = true;
    
    else if (ind.consultar_pare() != "$") {
        resultat = buscar_ascendent(consultar_individu(ind.consultar_pare()), nom);
        if (not resultat) resultat = buscar_ascendent(consultar_individu(ind.consultar_mare()), nom);
    }
    
    return resultat;
    
}

void Poblacio::buscar_arbre(Arbre<string>& arbre, string nom){
    
    Arbre<string> a1, a2;
    
    if (nom != "$"){
        buscar_arbre(a1, consultar_individu(nom).consultar_pare());
        buscar_arbre(a2, consultar_individu(nom).consultar_mare());
        arbre.plantar(nom, a1, a2);
    }
    
    else arbre.plantar(nom, a1, a2);
    
}

bool Poblacio::es_arbre_parcial(vector<string>& vecresultat, Arbre<string> acomplet, Arbre<string> aparcial){
    
    bool resultat = true;
    
    
    
    if (not acomplet.es_buit()) {
        if (aparcial.es_buit()) { // Si s'ha acabat l'arbre parcial afegim el que queda
            
            if (acomplet.arrel() != "$") vecresultat.push_back("*"+acomplet.arrel()+"*");
            else vecresultat.push_back(acomplet.arrel());
            
        }
        
        else if (aparcial.arrel() == "$" and  acomplet.arrel() != "$"){
            
            vecresultat.push_back("*"+acomplet.arrel()+"*");
            
        }
        else if (aparcial.arrel() == acomplet.arrel()){
            
            vecresultat.push_back(acomplet.arrel());
        }
        
        else if (aparcial.arrel() != acomplet.arrel()) {
            resultat = false;
        }
        
        if (resultat) {
            Arbre<string> ac1, ac2, ap1, ap2;
            
            acomplet.fills(ac1, ac2);
            if (not aparcial.es_buit()) aparcial.fills(ap1, ap2);
            if (resultat) resultat = es_arbre_parcial(vecresultat, ac1, ap1);
            if (resultat) resultat = es_arbre_parcial(vecresultat, ac2, ap2);
        }
        
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

bool Poblacio::comprovar_reproduccio(string npare, string nmare, string nfill){
    
    cout << "reproduccion_sexual " << nmare << ' ' << npare << ' ' << nfill << endl;
    
    bool resultat = existeix_individu(npare) and existeix_individu(nmare); // Cert si el nom dels pares estàn al sistema
    
    if (resultat) resultat = not existeix_individu(nfill); // Cert si el nom del fill no apareix al sistema
    
    if (not resultat) cout << "  error" << endl; // Primer punt d'error
    
    else {
        
        resultat = consultar_individu(npare).consultar_sexe() == 'Y' and consultar_individu(nmare).consultar_sexe() == 'X'; //  Cert si pare: Y i mare: X
        
        if (resultat and (consultar_individu(npare).consultar_pare() != "$")) {
            
            resultat = (consultar_individu(npare).consultar_pare() != consultar_individu(nmare).consultar_pare()) and (consultar_individu(npare).consultar_mare() != consultar_individu(nmare).consultar_mare()); // Cert si el pare i la mare no són germans (no tenen el mateix pare)
        }
        
        if (resultat) resultat = not buscar_ascendent(consultar_individu(npare), nmare); // Cert si el la mare no és ascendent del pare
        
        if (resultat) resultat = not buscar_ascendent(consultar_individu(nmare), npare); // Cert si el la mare no és ascendent de la mare
        
        if (not resultat) cout << "  no es posible reproduccion" << endl;
    }
    
    
    
    return resultat;
    
}


