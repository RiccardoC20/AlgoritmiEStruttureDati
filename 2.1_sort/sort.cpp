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

void merge(int* array, int start, int mid, int end) {
    int *array_appoggio = new int[start+end];
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
    int length = end - start + 1;
    for (int i = 0; i < length; i++) {
        array[start + i] = array_appoggio[i];
    }
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

void swap(int *array, int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

int perno (int *array, int start, int end) {
    int pivot = array[start];
    int j = start + 1;
    int i = j;
    
    while (i < end) {
        if(array[i] < pivot) {
            swap(array, i, j);
            j++;
        }
        i++;
    }

    array[start] = array[j];
    array[j] = pivot;

    return j;
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
    mergeSort(array, 0, N-1);  
    
    out.open("output.txt", ios::out);
    for (int i = 0; i < N; i++) {
        if (i%10 == 0) out << endl;
        out << array[i] << " ";
    }
    out.close();

    delete[] array;

    return 0;
}