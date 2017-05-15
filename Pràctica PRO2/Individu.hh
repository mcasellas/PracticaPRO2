/** @file Individu.hh
 @brief Especificació de la clase Individu.
*/

#ifndef _INDIVIDU_HH_
#define _INDIVIDU_HH_

#include "Parellcromosomes.hh"
#include "Especie.hh"



#ifndef NO_DIAGRAM
#include <iostream>

using namespace std;

#endif

/** @class Individu
 @brief Representa un individu.
 
 Permet llegir i consultar les dades que caracteritzen un individu de l'espècie.
 */
class Individu {

public:

    /** @brief Creadora por defecte.
     
        S'executa automàticament al declarar un individu.
        \pre <em>Cert</em>
        \post El resultat és un individu sense dades.
    */
    Individu();

    /** @brief Creadora d'un nou individu.
     
     \pre El paràmetre implicit està inicialitzat, l'explícit conté els individus que formaran la genètica del possible fill, els seus noms i el nom del possible fill. Es preparen pel canal d'entrada els cromosomes que s'usaràn per el creuament i el seu punt de tall d'acord amb N de Espècie.
     \post Si la reproducció és possible, es definirà l'individu. Si algun dels dos pares no existeix o el nom del fill ja ha estat usat es mostrarà un missathe d'error. En cas de no ser possible la reproducció es mostrarà el missatge "no es possible reproduccion".
     */
    
    
    
    void reproduir(Individu pare, Individu mare, string npare, string nmare, string nfill, const Especie& esp);

    
    
    /** @brief Consultora del sexe de l'individu.
     
     \pre El paràmetre implicit està inicialitzat.
     \post Es retorna el sexe de l'individu: X per noia, Y per noi.
    */
    char consultar_sexe() const;
    
    /** @brief Consultora d'un parell de cromosomes.
     
     \pre El paràmetre implicit està inicialitzat, l'explícit conté el parell de cromosomes que es vol.
     \post Es retorna el parell de cromosomes corresponent.
     */
    Parell_cromosomes consultar_parell_cromosomes(int i);
    
    /** @brief Consultora del nom del pare de l'individu.
     
     \pre El paràmetre implicit està inicialitzat.
     \post Es retorna el nom del pare de l'individu.
    */
    string consultar_pare() const;
    
    /** @brief Consultora del nom de la mare de l'individu.
     
     \pre El paràmetre implicit està inicialitzat.
     \post Es retorna el nom de la mare de l'individu.
     */
    string consultar_mare() const;
    
    /** @brief Escriptora del genotip de l'individu.
     
     \pre El paràmetre implicit està inicialitzat.
     \post S'imprimeix pel canal de sortida el genoma de l'individu del paràmetre implicit.
     */
    void escriure_genotip(Especie esp) const;


    void llegir_individu(Especie esp);

private:
    char sexe;
    vector<Parell_cromosomes> adn;
    string pare;
    string mare;
};

 #endif
