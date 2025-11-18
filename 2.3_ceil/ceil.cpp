#include <iostream>
#include <fstream>

using namespace std;

int binarySearch(const int* A, int check, int start, int end) {
    if (A[start] == A[end]) return A[end];
    int mid = (start + end)/2;
    if (A[mid] <= check) return binarySearch(A, check, mid + 1, end);
    else return binarySearch(A, check, start, mid);
}

int main() {

    int N, Nv;
    int *A, *V, *res;

    fstream in, out;
    in.open("input.txt", ios::in);
    in >> Nv >> N;
    A = new int[N];
    V = new int[Nv];
    res = new int[Nv];

    for (int i = 0; i < Nv; i++){
        in >> V[i];
    }
    for (int i = 0; i < N; i++){
        in >> A[i];
    }
    in.close();

    int max = A[N-1];
    int min = A[0];
    
    for (int i = 0; i < Nv; i++) {
        if (V[i] < min) {
            res[i] = min;
        } else if (V[i] > max) {
            res[i] = -1;
        } else {
            // ricerca binaria
            res[i] = binarySearch(A, V[i], 0, N);
        }
    }



    out.open("output.txt", ios::out);
    for (int i = 0; i < Nv; i++) out << res[i] << " ";
    out.close();

    return 0;
}