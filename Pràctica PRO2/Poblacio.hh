/** @file Poblacio.hh
 @brief Especificació de la clase Poblacio.
 */

#ifndef _POBLACIO_HH_
#define _POBLACIO_HH_

#include "Individu.hh"
#include "Arbre.hh"

#ifndef NO_DIAGRAM
#include <queue>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#endif

/** @class Poblacio
 @brief Representa una població.
 
 Permet establir un conjunt d'individus indexats per un nom i crear-ne o completar-ne l'arbre geneorològic a partir d'un individu. 
 */
class Poblacio {

public:

    /** @brief Creadora por defecte.
     
        S'executa automàticament al declarar una població.
        \pre <em>Cert</em>
        \post El resultat és una població sense individus.
    */
    Poblacio();

    /** @brief Consultora de l'individu que correspon al nom.
     
        \pre El paràmetre implicit està inicialitzat, l'explícit conté el nom de l'individu a buscar.
        \post Retorna l'individu que correspon al nom.
    */
    Individu buscar_individu(string nom);
    
    /** @brief Inclosora de la població.
     
        \pre El paràmetre implicit està inicialitzat, l'explícit conté l'individu a afegir.
        \post Afegeix l'individu a la població.
    */
    void afegir_individu(string nom, const Individu& p);
    
    
    
    bool comprovar_individu(string nom);


    /** @brief Escriptora de l'arbre geneaològic d'un individu.
     
        \pre El paràmetre implicit està inicialitzat. Es prepara pel canal d'entrada el nom de l'individu que serà l'arrel de l'arbre.
        \post S'imprimeix pel canal d'entrada l'arbre complet amb arrel establerta a l'individu.
    */
    void escriure_arbre(string nom);
    
    
    void buscar_descendents_cua(queue<string>& cua, Individu ind);
    
    
    /** @brief Completadora d'arbres.
     
        \pre El paràmetre implicit està inicialitzat. Es preparen pel canal d'entrada els elements coneguts d'un arbre geneaològic.
        \post S'imprimeix pel canal de sortida l'arbre complet amb arrel establerta a l'individu, marcant les individus que faltaven el d'entrada. Si l'arbre d'entrada no fos parcial es mostrarà "no es arbol parcial".
    */
    void completar_arbre();
    
    bool es_arbre_parcial(vector<string>& resultat, Arbre<string> acomplet, Arbre<string> aparcial);
    
    void buscar_arbre_complet(Arbre<string>& arbre, string nom);
    
    void llegir_arbre_parcial(Arbre<string>& nom);
    
    void escriure_vector(vector<string> resultat);
    
    
    /** @brief Completadora d'arbres.
     
        \pre El paràmetre implicit està inicialitzat.
        \post S'imprimeix pel canal de sortida tots els individus que formen la població per ordre alfabètic, amb el seu sexe i els noms del pare i de la mare.
    */
    void escriure_poblacio() const;
    

    void llegir_individu(Especie esp);

private:
    map<string,Individu> poble;
};


 #endif
