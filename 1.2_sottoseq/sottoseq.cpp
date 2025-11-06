#include <fstream>
#include <iostream>
using namespace std;

int main() {

    fstream in, out;
    int *array;
    int N = 0;
    in.open("input.txt", ios::in);
    in >> N;
    array = new int[N];
    for (int i = 0; i < N; i++) {
        in >> array[i];
    }
    in.close();

    int maxSoFar = 0;
    int max = 0;

    for (int i = 0; i < N; i++) {
        maxSoFar += array[i];
        if (maxSoFar < 0) maxSoFar = 0;
        if (maxSoFar > max) max = maxSoFar;
    }

    out.open("output.txt", ios::out);
    out << max;
    out.close();

    delete[] array;

    return 0;
}