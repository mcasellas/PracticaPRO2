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

bool Poblacio::comprovar_reproduccio(string npare, string nmare, string nfill){
    
    cout << "reproduccion_sexual " << nmare << ' ' << npare << ' ' << nfill << endl;
    
    
    bool resultat = true;
    
    resultat = comprovar_individu(npare) and comprovar_individu(nmare); // El nom dels pares estàn al sistema
    if (resultat) resultat = not comprovar_individu(nfill); // El nom del fill no apareix al sistema
    
    if (not resultat) cout << "  error" << endl;
    
    else {
        
        Individu pare, mare;
        
        pare = buscar_individu(npare);
        mare = buscar_individu(nmare);
        
        resultat = pare.consultar_sexe() == 'Y' and mare.consultar_sexe() == 'X';
        
        if (resultat and (pare.consultar_pare() != "$" or mare.consultar_pare() != "$")) resultat = (pare.consultar_pare() != mare.consultar_pare()) or (pare.consultar_mare() != mare.consultar_mare());
    
        
        if (resultat) resultat = not buscar_descendent(pare, nmare);
        
        if (resultat) resultat = not buscar_descendent(mare, npare);
        
        if (not resultat) cout << "  no es posible reproduccion" << endl;
    }
    
    
    
    return resultat;
    
}

bool Poblacio::buscar_descendent(Individu ind, string nom){
    
    bool resultat = false;
    
    if (ind.consultar_mare() == nom or ind.consultar_pare() == nom) resultat = true;
    
    else if (ind.consultar_pare() != "$") {
        resultat = buscar_descendent(buscar_individu(ind.consultar_pare()), nom);
        if (not resultat) resultat = buscar_descendent(buscar_individu(ind.consultar_mare()), nom);
    }
    
    return resultat;
    
}

void Poblacio::escriure_arbre(string nom){
    cout << "escribir_arbol_genealogico " << nom << endl;
    
    if (comprovar_individu(nom)){
        Arbre<string> complet;
        
        queue<string> cua_temp, cua_final;
        queue<int> niv_temp, niv_final;
        
        cua_temp.push(nom);
        
        niv_temp.push(0);
        
        buscar_arbre_nivells(buscar_individu(nom), cua_temp, cua_final, niv_temp, niv_final);
        
        
        int nivell = -1;
        
        while (not cua_final.empty()) {
            
            if (nivell != niv_final.front()) {
                if (nivell != -1) cout << endl;
                nivell = niv_final.front();
                cout << "  Nivel " << nivell << ':';
            }
            
            cout << " " << cua_final.front();
            
            cua_final.pop();
            niv_final.pop();
        }
        
        cout << endl;

        
    }
    
    else cout << "  error" << endl;
}

void Poblacio::buscar_arbre_nivells(Individu ind, queue<string>& cua_temp, queue<string>& cua_final, queue<int>& niv_temp, queue<int>& niv_final){

    while (not cua_temp.empty()){
        
        ind = buscar_individu(cua_temp.front());
        
        cua_final.push(cua_temp.front());
        niv_final.push(niv_temp.front());
        
        if (ind.consultar_pare() != "$" or ind.consultar_mare() != "$") {
            
        
            
            cua_temp.push(ind.consultar_pare());
            niv_temp.push(niv_temp.front()+1);
            
            cua_temp.push(ind.consultar_mare());
            niv_temp.push(niv_temp.front()+1);
        }
            cua_temp.pop();
            niv_temp.pop();
            
        
    }
}

void Poblacio::completar_arbre(){
    
    Arbre<string> aparcial, acomplet;
    
    llegir_arbre_parcial(aparcial);
    
    cout << "completar_arbol_genealogico " << aparcial.arrel() << endl;
    
    bool valid = comprovar_individu(aparcial.arrel());
    
    if (valid) {
    
        buscar_arbre_complet(acomplet, aparcial.arrel());
        
        vector<string> resultat;
        
        bool parcial = es_arbre_parcial(resultat, acomplet, aparcial);
        
        if (parcial) {
            cout << "  ";
            escriure_vector(resultat);
            
        }
        
        else valid = false;
    
    }
    
    if (not valid) cout << "  no es arbol parcial" << endl;
    
    
}

void Poblacio::escriure_vector(vector<string> resultat){ // Es podria posar en la funció
    for (int i = 0; i < resultat.size(); i++){
        cout << resultat[i];
        if (i != resultat.size()-1) cout << ' ';
    }
    
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

bool Poblacio::es_arbre_parcial(vector<string>& vecresultat, Arbre<string> acomplet, Arbre<string> aparcial){
    
    bool resultat = true;
 
    
    
    if (not acomplet.es_buit()) {
        if (aparcial.es_buit()) { // Si és buit no podem obtenir l'arrel
            
            if (acomplet.arrel() != "$") vecresultat.push_back("*"+acomplet.arrel()+"*");
            else vecresultat.push_back(acomplet.arrel());
        }
        
        else if (aparcial.arrel() == "$" and  acomplet.arrel() != "$"){
            
            vecresultat.push_back("*"+acomplet.arrel()+"*");
            
        }
        else if (aparcial.es_buit() or (aparcial.arrel() == acomplet.arrel())){
            
            vecresultat.push_back(acomplet.arrel());
        }
        
        else if (aparcial.arrel() != acomplet.arrel()) {
            resultat = false;
        }
        
        Arbre<string> ac1, ac2, ap1, ap2;
        
        acomplet.fills(ac1, ac2);
        if (not aparcial.es_buit()) aparcial.fills(ap1, ap2);
        if (resultat) resultat = es_arbre_parcial(vecresultat, ac1, ap1);
        if (resultat) resultat = es_arbre_parcial(vecresultat, ac2, ap2);
        
        
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
    
    cout << "escribir_poblacion" << endl;
    
    for (map<string,Individu>::const_iterator it = poble.begin(); it != poble.end(); it++) {
        cout << "  " << (*it).first << " X" << (*it).second.consultar_sexe() << " (" << (*it).second.consultar_pare() << ',' << (*it).second.consultar_mare() << ')' << endl;
    }

}


void Poblacio::llegir_individu(Especie esp){
    
    Individu ind;
    string nom;

    cin >> nom;
    
    cout << "anadir_individuo " << nom << endl;
    
    if (not comprovar_individu(nom)) {
        ind.llegir_individu(esp);

        afegir_individu(nom,ind);
        
       
    }
    
    else cout << "  error" << endl;

}
