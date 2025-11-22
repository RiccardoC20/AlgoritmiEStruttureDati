#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;



struct node {
    int val;
    vector<node*> children;
    node(int n = 0) : val(n){};     // questo crea il costruttore per val di un nuovo nodo
};

void createTree (const unordered_map<int , vector<int>> map, node* radice) {
    auto it = map.find(radice->val);        // mi torna un iteratore
    if (it == map.end()) {}
}

int main() {

    /**
     *  1) leggo il file e lo salvo con in una struttura dati apposita
     *  2) applico un algoritmo per popolare il mio albero con le struct nodi
     *  3) applico i tre algoritmi di attraversamento dell'albero e stampo le risposte in output
     */

    vector <pair<int,int>> lettura;
    fstream in, out;
    int numNodi, valRadice, a, b;

    /**
     *  La soluzione migliore è quella di creare una mappa nodo-figli che si implementa unordered_map di valore -> lista di figli.
     *  Per farlo mi serve una struttura dati adatta
     * 
     */

    unordered_map<int, vector<int>> map;

    in.open("input.txt", ios::in);
    in >> numNodi >> valRadice;
    for (int i = 0; i < numNodi; i++) {
        in >> a >> b;
        map[a].push_back(b);
    }
    in.close();

    cout << "Lettura del file" << endl;

    // Creazione della struttura dati dalla radice
    node* radice = new node(valRadice);
    createTree(map, radice);




    out.open("output.txt", ios::out);

    out.close();


    return 0;
}