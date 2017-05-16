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

void Poblacio::escriure_arbre(string nom){
    cout << "escribir_arbol_genealogico " << nom << endl;
    
    if (comprovar_individu(nom)){
        Arbre<string> complet;
        
        list<string> llista;
        
        llista.push_back(nom);
        
        
        buscar_arbre_nivells(buscar_individu(nom), llista);
        
        for (list<string>::iterator it = llista.begin(); it != llista.end(); it++){
            cout << " " << *it;
        }

        
    }
    
    else cout << "  error" << endl;
}

void Poblacio::buscar_arbre_nivells(Individu ind, list<string>& llista){
    
    list<string>::iterator it = llista.end();
    
    if (ind.consultar_pare() != "$") {
   
        
        llista.insert(it, ind.consultar_pare());
        llista.insert(it, ind.consultar_mare());

        buscar_arbre_nivells(buscar_individu(ind.consultar_pare()), llista);
        buscar_arbre_nivells(buscar_individu(ind.consultar_mare()), llista);

    }
    
}

void Poblacio::escriure_temp(Arbre<string> a){
    if (not a.es_buit()) {
        Arbre<string> a1;
        Arbre<string> a2;
        string x = a.arrel();
        a.fills(a1,a2);
        escriure_temp(a1);
        cout << " " << x;
        escriure_temp(a2);
        a.plantar(x,a1,a2);
    }
}

//void Poblacio::escriure_arbre(string nom){ // Mirar estrucutra per amplada !!!!!!!
//    
//    cout << "escribir_arbol_genealogico " << nom << endl;
//    
//    if (comprovar_individu(nom)){
//    
//    queue<string> cua;
//    
//    buscar_descendents_cua(cua, buscar_individu(nom));
//    
//    cout << "  Nivell 0: " << nom << endl;;
//    
//    int nivell = 1;
//    int parelles = 2;
//    
//    while (not cua.empty()){
//        
//        
//        
//        cout << "  Nivell " << nivell << ": ";
//        
//        int i = 0;
//        
//        while (i < parelles and not cua.empty()) {
//            if (cua.front() != "$") cout << cua.front();
//            if (i < parelles-1) cout << " ";
//            cua.pop();
//            ++i;
//        }
//        
//        cout << endl;
//        ++nivell;
//        parelles *= 2;
//        
//        while (cua.front() == "$") cua.pop();
//    }
//    }
//    
//    else cout << "  error" << endl;
//    
//    
//}

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

void Poblacio::escriure_vector(vector<string> resultat){
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
            
            vecresultat.push_back(acomplet.arrel());
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
