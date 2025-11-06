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
    

    int** mat = new int*[R];
    for (int i = 0; i < R; i++) {
        mat[i] = new int[C];
    }

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            in >> mat[row][col];
//            cout << mat[row][col] << " ";
        }
//        cout << endl;
    }
    in.close();

    int max = 0;
    int *tmp = new int[C];

    // popolo tmp di zeri
    for (int i = 0; i < C; i++) tmp[i] = 0;


    for (int top = 0; top < R; top++) {
//        cout << "Top: "  << top << endl;
        for (int bot = top; bot < R; bot++) {
            for (int col = 0; col < C; col++) {
                // aggiorno tmp
                tmp[col] += mat[bot][col];
            }
            max = Kadane(max, tmp, C);
 //           cout << "\tBot: "  << bot << endl;
        }
        
        // avanzo top di una riga e rimuovo da tmp
        for (int col = 0; col < C; col++) {
            //aggiorno tmp
            tmp[col] -= mat[top][col];
        }    
        top++;
//        cout << "Top: "  << top << endl;
        
        for (int bot = R-1; bot >= top; bot--) {
            //Kadane
            max = Kadane(max, tmp, C);
            //Rimuovo una riga da tmp
            for (int col = 0; col < C; col++) {
                tmp[col] -= mat[bot][col];
            }
//            cout << "\tBot: " << bot << endl;
        }

    }

    out.open("output.txt", ios::out);
    out << max;
    out.close();

    
    //Dealloco la matrice 
    for (int i = 0; i < R; i++) {
        delete[] mat[i];
    }
    delete[] mat;
   
    delete[] tmp;
    return 0;
}