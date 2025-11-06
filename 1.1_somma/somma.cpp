#include <fstream>

using namespace std;

int main() {

    fstream in, out;
    int a,b;
    in.open("input.txt", ios::in);
    in >> a >> b;
    in.close();

    out.open("output.txt", ios::out);
    out << a+b;
    out.close();

    return 0;
}