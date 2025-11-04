#include <iostream>
#include <fstream>

using namespace std;

fun ordin

int main() {    
    fstream in, out;
    int N = 0;

    in.open("sortpesato_input.txt", ios::in);
    in >> N;    

    int array[N];

    for (int i = 0; i < N; i++) {
        if (i == array[i]) continue;
        else ordinaCiclo(array[N], i);
    }


    for (int i = 0; i < N; i++) {
        in >> array[i];
        
    }


    out.open("sortpesato_output.txt", ios::out);

    for (int i = 0; i < N; i++) {
        out << array[i] << " ";
    }


    return 0;
}