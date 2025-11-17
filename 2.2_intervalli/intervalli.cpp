#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N = 0;
    int a, b;
    vector<pair<int, int>> data;

    fstream in, out;
    in.open("input.txt", ios::in);
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> a >> b;
        data.push_back({a,b});
    }
    in.close();

    // algoritmo di sort dove uso una lambda function per definire l'operatore di ordinamento
    sort(data.begin(), data.end(),
        [] (const pair<int,int>&a, const pair<int,int>&b) {
            if (a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        }
    );


    
    int intervalloNonCopertoMax = 0;
    int inizioIntervalloNonCoperto, fineIntervalloNonCoperto = inizioIntervalloNonCoperto = 0;


    int index = 1;
    while (index < N && data[index].first == data[index - 1].first) {
        index++;
    }
    index--; // ora dovrei essere fermo al primo intervallo più grande di data[0].first

    int min, max;
    int maxRightEscluso = data[index].second;
    // cout << data[index].first << " " << data[index].second << endl;

    index ++;

    // da qui posso continuare a scorrere avendo un maxRight vero
    for (; index < N; index ++) {
        if (data[index-1].first == data[index].first) continue;
        // devo per forza controllare se aggiornare MaxRight no? 
        if (data[index - 1].second > maxRightEscluso) maxRightEscluso = data[index - 1].second;
        // ora controllo se con il nuovo data[index].first supero maxRightEscluso
        if (data[index].first > maxRightEscluso) { // allora ho un intervalloNonCoperto 
            int grandezzaIntervallo = data[index].first - maxRightEscluso;
            if (grandezzaIntervallo > intervalloNonCopertoMax) {
                intervalloNonCopertoMax = grandezzaIntervallo;
                inizioIntervalloNonCoperto = maxRightEscluso;
                fineIntervalloNonCoperto = data[index].first;
            }
        }
    }

    out.open("output.txt" ,ios::out);
    if (inizioIntervalloNonCoperto == fineIntervalloNonCoperto) out << 0;
    else out << inizioIntervalloNonCoperto << " " << fineIntervalloNonCoperto;
    out.close();


    return 0;
}