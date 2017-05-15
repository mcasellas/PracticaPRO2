
#include "ArbIO.hh"

void llegir_arbre_string(Arbre<string>& a, int coneguts, int desconeguts){
/* Pre: a es buit; el canal estandar d'entrada conte el recorregut en preordre
   d'un arbre binari A d'enters marcat amb "marca" */  
/* Post: a = A */
    Arbre<string> a1;
    Arbre<string> a2;
    string x;
    cin >> x;
  
    if (desconeguts != coneguts+1){
    
        if (x != "$") {
            ++coneguts;
            llegir_arbre_string(a1, coneguts, desconeguts);
            llegir_arbre_string(a2, coneguts, desconeguts);
            a.plantar(x,a1,a2);
        }
        else ++desconeguts;
    }
    
    
}

void escriure_arbre_string(Arbre<string>& a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conte el recorregut en inordre d'a */
  if (not a.es_buit()) {
    Arbre<string> a1;
    Arbre<string> a2;
    string x = a.arrel();
    a.fills(a1,a2);
    cout << " " << x;
    escriure_arbre_string(a1);
    
    escriure_arbre_string(a2);
    a.plantar(x,a1,a2);
  }
    
    
}
