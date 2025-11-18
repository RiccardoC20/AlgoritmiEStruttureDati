#include <fstream>
#include <iostream>

using namespace std;

void insertionSort (int* array, int N) {
    for (int i=1; i<N; i++) {
        int tmp = array[i];
        int j = i; 
        while (j > 0 && tmp < array[j-1]) {     // non arrivo alla posizione 0 e mi fermo quando tmp >= array[j] : allora so dove inserirlo
            array[j] = array[j-1];            // porto avanti
            j--;
        }    
        array[j] = tmp;
    }
}

/**
 *    Merge Sort Algorithm 
 *      - mergeSort
 *      - merge
 * 
 *     Serve un array di appoggio per ricopiare gli elementi ordinati
 */


void merge(int* array, int start, int mid, int end) {
    int length = end - start + 1;
    int *array_appoggio = new int[length];
    int k = 0;
    int i = start;
    int j = mid +1;
    
    // creo l'array_appoggio usando i minimi dei due array
    while (i <= mid && j <= end) {
        if (array[i] <= array[j]) {
            array_appoggio[k] = array[i];
            i++;
        } else {
            array_appoggio[k] = array[j];
            j++;
        }
        k++;
    }

    // completo l'array_appoggio con eventuali rimanenti
    while (i<=mid) {
        array_appoggio[k++] = array[i++];
    }
    while (j<=end) {
        array_appoggio[k++] = array[j++];
    }

    // ricopio dall'array_appoggio all'array normale
    
    for (int i = 0; i < length; i++) {
        array[start + i] = array_appoggio[i];
    }

    delete[] array_appoggio;
}

void mergeSort (int* array, int start, int end) { 
    // caso base di un array
    if (start >= end) return;   // l'array è di un solo elemento
        
    // trovo la nuova metà
    int mid = (start + end)/2;

    // applico Divide 
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);

    //applico merge 
    merge(array, start, mid, end);  // ora ordino i due blocchi già ordinati
}

/**
 *      QuickSort Algorithm
 *      - QuickSort
 *      - Pivot
 *      - Swap
 * 
 *      Come in MergeSort il tutto viene eseguito su un array che non viene mai spezzettato. Vengono usati
 *      due indici start ed end per delimitare la porzione di array su cui voler eseguire le operazioni
 */


void swap(int *array, int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

int pivot (int *array, int start, int end) {
    // Il pivot è al primo posto dell'array.
    int pivot = array[start];
    // i è l'indice dell'elemento da analizzare
    int i = start + 1;
    // j è l'indice dei minori di pivot. N.b. all'inizio è in start perché sono stati trovati 0 elementi 
    // minori di pivot.
    int j = start;
    
    // scorro l'array fino ad end
    while (i <= end) {  
        // se pivot è maggiore dell'elemento in posizione i-esima allora lo sposto
        if(pivot > array[i]) {
            j++;                    // prima autmento j
            swap(array, i, j);      // poi swappo
        }
        i++;                        // i avanza
    }

    // posiziono pivot tra le due parti (quella superiore e quella inferiore)
    array[start] = array[j];        // il j-esimo è un minore e lo copio in prima posizione
    array[j] = pivot;               // copio pivot nel j-esimo posto ora

    return j;                       // ritorno la posizione in cui è pivot
}

void quickSort (int *array, int start, int end) {
    if (start >= end) return;                        // fondamentale per il caso base
    int posizione_perno = pivot(array, start, end);  // trovato la posizione di dove si trova il perno non mi resta che lanciarlo sui segmenti non ordinati
    quickSort (array, start, posizione_perno - 1);
    quickSort (array, posizione_perno + 1, end);
}



int main() {
    fstream in, out;
    int N = 0;
    int *array;
    in.open("input.txt", ios::in);
    in >> N;
    array = new int[N];
    for (int i = 0; i < N; i++) { 
        in >> array[i];
    }
    in.close();

    // sorting algoritms
    quickSort(array, 0, N-1);  
    // mergeSort(array, 0, N-1);
    
    
    out.open("output.txt", ios::out);
    for (int i = 0; i < N; i++) {
        out << array[i] << " ";
        cout << array[i] << " ";
    }
    out.close();

    delete[] array;

    return 0;
}