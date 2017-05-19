/**
 * @mainpage Disseny modular: Experiments genètics en un laboratori.

S'ofereix un menú d'opcions per gestionar les classes que formen part de l'experiment genètic. S'introdueixen les classes <em>Especie</em> i <em>Poblacio</em>.

Nomès es documenten elements públics.
*/

/** @file main.cc
    @brief Programa principal de la pràctica <em><b>Experiments genètics en un laboratori</b></em>.
*/


#include "Especie.hh"
#include "Poblacio.hh"
#include "Individu.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif



/** @brief Programa principal de la pràctica <em>Experiments genètics en un laboratori</em>.
*/
int main(){

    Especie esp;

    esp.establir_genetica();

    Poblacio poble;
    
    int ninicials;
    
    cin >> ninicials;
    
    for (int i = 0; i < ninicials; i++) {
        Individu ind;
        string nom;
        
        cin >> nom;
        
        ind.llegir_individu(esp);
            
        poble.afegir_individu(nom,ind);

        
    }
    
    string accio;

    while (cin >> accio and accio != "acabar"){
        
        if (accio == "anadir_individuo"){
            poble.llegir_individu(esp);
        }

        else if (accio == "reproduccion_sexual"){
            string nmare, npare, nfill;
            cin >> nmare >> npare >> nfill;
            
            if (poble.comprovar_reproduccio(npare, nmare, nfill)){
                
                Individu fill;

                fill.reproduir(poble.consultar_individu(npare), poble.consultar_individu(nmare), npare, nmare, esp);

                poble.afegir_individu(nfill, fill);
            }
        }
        
        else if (accio == "escribir_arbol_genealogico"){
            string nom;
            cin >> nom;
            poble.escriure_arbre_genealogic(nom);
        }

        else if (accio == "completar_arbol_genealogico"){
            poble.completar_arbre();
        }

        else if (accio == "escribir_poblacion"){
            poble.escriure_poblacio();
        }

        else if (accio == "escribir_genotipo"){
            string nom;
            cin >> nom;
            
            cout << "escribir_genotipo " << nom << endl;
            
            if (poble.existeix_individu(nom)) poble.consultar_individu(nom).escriure_genotip();
            
            else cout << "  error" << endl;
        }
    }
    
    cout << "acabar" << endl;

    
    
}
