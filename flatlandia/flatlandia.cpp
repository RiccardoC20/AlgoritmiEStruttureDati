/**
 *  Progetto: NATALE A FLATLANDIA
 * 
 *  Quesito finale: data la lista di triangoli ed il loro orientamento, 
 *  trovare quali triangoli potrebbero rimanere solitari.
 *  
 *  Ragionamento: 
 *      - quelli che potrebbero rimanere da soli è complementare a quelli che sicuramente escono.
 *      Obiettivo: trovare quelli che sicuramente escono.
 *          esiste una configurazione per non farlo uscire? Riesco a non farlo uscire?
 *          => se riesco a non farlo uscire per il lato destro che per il lato sinistro allora potrebbe 
 *             rimanere da solo per ultimo.
 *              
 *      - Valuto per ogni elemento dell'array le celle alla sinistra e alla destra: però le due parti 
 *        non si influenzano quindi per ogni cella devo trovare per lato dx e sx dei modi per azzerarla 
 *        lasciando l'elemento iniziale
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

struct doubleBool {
    bool left = false;
    bool right = false;
};

int main() {

    int N = 0;
    char *string;
    doubleBool *arrayBool;
    fstream in, out;
    in.open("input.txt", ios::in);
    in >> N;
    string = new char[N];
    arrayBool = new doubleBool[N];


    for (int i = 0; i < N; i++) {
        in >> string[i];
        
    }
    in.close();

    // calcolo tutti i casi elemento per elemento
    for (int i = 0; i < N; i++) {
        
    }

    delete[] string;
    return 0;
}