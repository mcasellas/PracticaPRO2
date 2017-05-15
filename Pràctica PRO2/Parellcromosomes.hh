/** @file Parellcromosomes.hh
    @brief Especificació de la clase Parell_cromosomes.
*/

#ifndef _PARELLCROMOSOMES_HH_
#define _PARELLCROMOSOMES_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;



/** @class Parell_cromosomes
 @brief Representa un parell de cromosomes.
 
 Permet llegir i consultar un parell concret de cromosomes.
 */
class Parell_cromosomes
{

public:

    // Creadora per defecte
    /** @brief Creadora por defecte.
     
        S'executa automàticament al declarar un parell de cromosomes.
        \pre <em>Cert</em>
        \post El resultat és un parell de cromosomes sense gens.
    */
    Parell_cromosomes();
    
    
    /** @brief Creuadora de dos cromosomes.
     
     \pre El paràmetre explicit conté el parell de cromosomes del pare, de la mare, el seleccionat pel pare, el de la mare i el punt de tall.
     \post Es retorna el parell de cromosomes corresponent al fill.
     */
    void creuament(Parell_cromosomes pare, Parell_cromosomes mare, int npare, int nmare, int k, int lo);

    
    
    /** @brief Lectora del material genètic.
     
     \pre El paràmetre implicit està inicialitzat. El canal d'entrada conté la informació genètica del parell de cromosomes.
     \post Es guarda la informació dins de cada cromosoma.
     */
    void llegir_cromosomes_no_sexuals(int llargada_parell);
    
    
    void llegir_cromosomes_sexuals(int llargada_lx, int llargada_ly, char sexe);

    void escriure_cromosoma(int num) const;
    
    vector<int> consultar_cromosoma(int num) const;


private:
    vector<int> c1;
    vector<int> c2;

};

 #endif

