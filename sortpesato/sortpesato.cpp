#include <iostream>
#include <fstream>

using namespace std;

int main() {    
    fstream in, out;
    int N = 0, numeroScambiTOT = 0, prezzoScambi = 0;

    in.open("input.txt", ios::in);
    in >> N;    

    int* array;
    array = new int[N];
    
    // lettura dell'array
    for (int i = 0; i < N; i++) {
        in >> array[i];
       // cout << array[i] << " ";
    }
    in.close();

    for (int i = 0; i < N; i++) {
        //se è già ordinato o è 0 (quindi è già stato ordinato) allora saltalo
        if (i+1 == array[i] || array[i] == 0) continue; 
        int current = array[i];
        int numScambi = 0;
        int min = current;
        int sum = current;
        array[i] = 0;

        while (current != i+1) {  
            int a = array[current-1];
            array[current - 1] = 0;
            current = a;
            numScambi++;
            sum += current;
            if (min > current) min = current;
        }
        
       // cout << "\n\tDati del ciclo: numScambi, min, sum: " << numScambi << " " << min << " " << sum << endl; 
        numeroScambiTOT += numScambi;
        if (numScambi*min < 2*(min+1) + numScambi) {
            //SENZA usare l'1
            prezzoScambi += (sum - min) + numScambi*min;
        } else {
            //USANDO l'1
            prezzoScambi += 2*(min+1) + (sum - min) + numScambi;
        }
       // cout << "numeroScambiTot, prezzoScambi: " << numeroScambiTOT << " " << prezzoScambi;
    }
  
    // stampa dell'array
    /*
    cout << "\nArray pulito:" << endl;
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    */

    out.open("output.txt", ios::out);
    out << numeroScambiTOT << " " << prezzoScambi;
    out.close();


    return 0;
}