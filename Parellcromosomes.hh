/** @file Parellcromosomes.hh
 @brief Especificació de la clase parellcromosomes.
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
class Parell_cromosomes {
    
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
    
    
    
    
private:
    /** @brief Cromosoma 1 */
    vector<int> c1;
    /** @brief Cromosoma 2 */
    vector<int> c2;
    
    /** @brief Consultora d'un cromosoma.
     
     \pre El paràmetre explicit està inicialitzat amb el número del cromosoma que es vol consultar (0 pel primer, 1 pel segon).
     \post Es retorna el vector corresponent al cromosoma del paràmetre explícit.
     */
    vector<int> consultar_cromosoma(int num) const;
    
};

#endif

