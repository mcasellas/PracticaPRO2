/** @file Poblacio.hh
 @brief Especificació de la clase poblacio.
 */

#ifndef _POBLACIO_HH_
#define _POBLACIO_HH_

#include "Individu.hh"


#ifndef NO_DIAGRAM
#include "Arbre.hh"
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

    
    /** @brief Consultora de l'individu corresponent al nom.
     
        \pre El paràmetre implicit està inicialitzat, l'explícit conté el nom de l'individu a buscar.
        \post Retorna l'individu que correspon al nom.
    */
    Individu consultar_individu(string nom);
    
    
    /** @brief Comprovadora de l'existència d'un individu.
     
     \pre El paràmetre implicit està inicialitzat, l'explícit conté el nom de l'individu a comprovar.
     \post Si existeix l'individu a la població retrorna cert, en cas contrari, retorna fals.
     */
    bool existeix_individu(string nom);
    

    /** @brief Inclosora de la població.
     
        \pre El paràmetre implicit està inicialitzat, l'explícit conté el nom i l'individu a afegir.
        \post Afegeix l'individu a la població.
    */
    void afegir_individu(string nom, const Individu& p);
    
    
    /** @brief Reproducció d'individus del poble.
     
     \pre El paràmetre implicit està inicialitzat, l'explícit conté el dels pares, el de l'individu a afegir i l'espècie.
     \post Si és possible la reproducció, s'afegeix el fill al poble, en cas contrari es retornarà l'error corresponent.
     */
    void reproduir(string pare, string mare, string fill, Especie esp);
    

    /** @brief Escriptora de l'arbre geneaològic d'un individu.
     
        \pre El paràmetre implicit està inicialitzat. Es prepara pel canal d'entrada el nom de l'individu que serà l'arrel de l'arbre.
        \post S'imprimeix pel canal d'entrada l'arbre complet, per nivells, amb arrel establerta a l'individu.
    */
    void escriure_arbre_genealogic(string nom);
    
    
    /** @brief Completadora d'arbres.
     
        \pre El paràmetre implicit està inicialitzat. Es preparen pel canal d'entrada el nom dels individus coneguts d'un arbre geneaològic.
        \post S'imprimeix pel canal de sortida l'arbre complet amb arrel establerta a l'individu, marcant les individus que faltaven a l'arbre d'entrada. Si l'arbre d'entrada no fos parcial (hi haguessin incoherències o es tractés d'un arbre complet) es mostrarà "no es arbol parcial" pel canal de sortida.
    */
    void completar_arbre();
    
    /** @brief Escriptora de la població.
     
        \pre El paràmetre implicit està inicialitzat.
        \post S'imprimeix pel canal de sortida tots els individus que formen la població per ordre alfabètic, amb el seu sexe i els noms del pare i de la mare.
    */
    void escriure_poblacio() const;
    
    /** @brief Lectora d'un individu de la població.
     
     \pre El paràmetre implicit està inicialitzat i l'explicit conté la espècie del individu a llegir. Es prepara pel canal d'entrada el nom de l'individu.
     \post Si l'individu no existeix a la població, s'hi afegeix.
     */
    void llegir(Especie esp);
    
    
    /** @brief Lectora dels primers individus de la població.
     
     \pre El paràmetre implicit està inicialitzat i l'explicit conté la espècie del individu a llegir. Es preparen pel canal d'entrada el número d'individus inicials i els noms dels individus.
     \post S'afegeixen els individus a la població amb els pares establerts a "$"
     */
    void llegir_inicials(Especie esp);
    

private:
    
    /** @brief Comprovadora d'ascendents.
     
     \pre El paràmetre explicit conté l'individu del qual es vol coneixer si el segon paràmetre, el nom de l'individu a buscar, és un ascendent seu.
     \post Si el nom és un ascendent de l'individu es retorna cert, en cas contrari es retorna fals..
     */
    bool buscar_ascendent(Individu ind, string nom);
    
    /** @brief Creadora d'arbre complet d'un individu.
     
     \pre El paràmetre explicit conté l'arbre a omplir i el nom de l'individu del qual volem crear l'arbre complet (cert).
     \post Es retorna per referència l'arbre complet corresponent al nom de l'individu del paràmetre explicit.
     */
    void buscar_arbre(Arbre<string>& arbre, string nom);
    
    /** @brief Comprovadora d'arbre parcial.
     
     \pre El paràmetre explícit conté el vector a retornar en cas que sigui arbre parcial, l'arbre complet amb el qual volem comparar l'arbre parcial, que és el tercer paràmetre.
     \post Es retorna cert si es tracta d'un arbre parcial i es retorna per referència un vector amb l'arbre parcial completat. En cas contrari, es retorna fals.
     */
    bool es_arbre_parcial(vector<string>& resultat, Arbre<string> acomplet, Arbre<string> aparcial);
    
    
    /** @brief Lectora de l'arbre parcial.
     
     \pre El paràmetre explicit conté l'arbre que es retornarà. Pel canal d'entrada es preparen els noms dels individus coneguts d'un arbre genealògic.
     \post Es retorna per referència l'arbre parcial que s'ha llegit a través del canal d'entrada.
     */
    void llegir_arbre_parcial(Arbre<string>& a);
    
    
    /** @brief Comprovadora de la capacitat de reproducció.
     
     \pre El paràmetre implicit està inicialitzat, l'explícit conté el dels pares i el de l'individu a afegir.
     \post Retorna cert si els els compleixen les condicions per poder-se reproduïr i el fill no existeix fins al moment. En cas contrari, retorna fals i s'escriu l'error corresponent pel canal de sortida.
     */
    bool comprovar_reproduccio(string pare, string mare, string fill);
    
    
    /** @brief Representa una població
        
        Enllaça els individus pel seu nom i està ordenat per ordre alfabètic*/
    map<string,Individu> poble;
};


 #endif
