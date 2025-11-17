#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



int chiManca(const vector<int>& v, int start, int end) {
    if (start == end) return start;

    int mid = (start+end)/2;
    if (mid == v[mid]) {
        return chiManca(v, mid + 1, end);
    } else {
        return chiManca(v, start, mid);
    }

}

int chiMancaExt(const vector<int>& v) {
    if (v.size() - 1 == v[v.size() -1]) return v.size();
    else return chiManca(v, 0, v.size()-1);
}

int main () {
    
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};
    cout << "L'elemento mancante e': " << chiMancaExt(v);
}