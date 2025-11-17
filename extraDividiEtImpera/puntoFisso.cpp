#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
bool puntoFisso(const vector<int>& vector, int start, int end);

bool puntoFissoExtended(const vector<int>& vector) {
    int end = vector.size()-1;
    return puntoFisso(vector, 0, end);
}

bool puntoFisso(const vector<int>& vector, int start, int end){
    
    // Questo può essere sistemato meglio. Il caso finale potrebbe essere quando start > end
    // facendo così il codice sottostante fa il controllo se c'è un punto fisso.
    if (start == end) {                         
        if (vector[start] == start) return true;
        else return false;
    }

    int media = (start + end)/2;
    if (vector[media] == media) return true;
    else if (vector[media] < media) return puntoFisso(vector, media+1, end);
    else return puntoFisso(vector, start, media-1);
}

int main () {
    
    vector<int> v = {-3, 0, 1, 3};
    if (puntoFissoExtended(v)) {
        cout << "il vettore contiene un punto fisso" << endl;
    } else {
        cout << "il vettore non contiene un punto fisso" << endl;
    }

}