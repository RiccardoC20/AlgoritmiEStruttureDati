#include <fstream>

using namespace std;




int main() {

    fstream in, out;
    int N = 0;
    int *array = new int[N];

    in.open("input.txt", ios::in);
    in >> N;
    for (int i = 0; i < N; i++) in >> array[i];
    in.close();

    // sorting algoritms

    
    
    out.open("output.txt", ios::out);
    for (int i = 0; i < N; i++) out << array[i] << " ";
    out.close();

    delete[] array;

    return 0;
}