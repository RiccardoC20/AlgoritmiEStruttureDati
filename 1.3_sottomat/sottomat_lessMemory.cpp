#include <fstream>
#include <iostream>
using namespace std;


int Kadane(int max, int* tmp, int C) {
    int maxSoFar = 0;
//    cout << "\t\tKadane con :";
    for (int i = 0; i < C; i++){
//        cout << tmp[i] << " ";
        maxSoFar += tmp[i];
        if (maxSoFar > max) max = maxSoFar;
        if (maxSoFar < 0) maxSoFar = 0;
    }
//    cout << endl << "\t\t\tMax: " << max << endl;
    return max;
}

int main() {

    fstream in, out;
    int R = 0, C = 0;
    in.open("input.txt", ios::in);
    in >> R >> C;
    in.close();

    int max = 0;
    string tmpString;


    for (int top = 0; top < R; top++) {
        // azzero tmp
        int tmp[2000] = {0};

        in.open("input.txt", ios::in);
        in >> R >> C;
//        cout << "Top: "  << top << endl;

        // Skippo le prime top righe
        for (int i = 0; i<=top; i++) {
            getline(in, tmpString);
//            cout << "\t\t ho letto la linea: " << tmpString << endl;
        }

        for (int bot = top; bot < R; bot++) {
//            cout << "Leggo: " << endl;
            int letturaInt = 0;
            for (int col = 0; col < C; col++) {
                // aggiorno tmp
                in >> letturaInt;
                tmp[col] += letturaInt;
//                cout << letturaInt << " ";
            }
            max = Kadane(max, tmp, C);
//            cout << "\tBot: "  << bot << endl;
        }
        
        in.close();
    }
        
    out.open("output.txt", ios::out);
    out << max;
    out.close();

    return 0;
}