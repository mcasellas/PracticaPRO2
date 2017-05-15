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
        poble.llegir_individu(esp);
        
    }
    
    string accio;

    while (cin >> accio and accio != "acabar"){
        
        if (accio == "anadir_individuo"){
            poble.llegir_individu(esp);
        }

        else if (accio == "reproduccion_sexual"){
            string nmare, npare, nfill;
            cin >> nmare >> npare >> nfill;
            
            cout << "reproduccion_sexual " << nmare << ' ' << npare << ' ' << nfill << endl;

            Individu pare, mare, fill;
            
            if (not poble.comprovar_individu(nmare) or not poble.comprovar_individu(npare) or poble.comprovar_individu(nfill)) cout << "  error" << endl;
            
            else {
            
            mare = poble.buscar_individu(nmare);
            pare = poble.buscar_individu(npare);
            
            if (pare.consultar_sexe() != 'Y' or mare.consultar_sexe() != 'X') cout << "  no es posible reproduccion" << endl;
            
            else{
                fill.reproduir(pare, mare, npare, nmare, nfill, esp);

                poble.afegir_individu(nfill, fill);
            }
                
            }

        }

        else if (accio == "escribir_arbol_genealogico"){
        
            string nom;
            cin >> nom;
            
            if (poble.comprovar_individu(nom)) poble.escriure_arbre(nom);
            else cout << "  error" << endl;
            
        }

        else if (accio == "completar_arbol_genealogico"){
            poble.completar_arbre();
            
            //cout << "no es arbol parcial" << endl;
        }

        else if (accio == "escribir_poblacion"){
            poble.escriure_poblacio();
        }

        else if (accio == "escribir_genotipo"){
            Individu ind;
            string nom;
            cin >> nom;
            
            if (poble.comprovar_individu(nom)){
            
                ind = poble.buscar_individu(nom);
                
                ind.escriure_genotip(esp);
            }
            
            else cout << "  error" << endl;
        }
    }

    
    
}
