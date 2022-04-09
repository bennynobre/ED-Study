#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void mostrar(vector<string> mapa){
    for(auto line : mapa)
        cout << line << '\n';
    getchar();
}

int queimar(vector<string>& mapa, int lpos, int cpos) {
    int nl = mapa.size();
    int nc = mapa[0].size();
    if (lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc)
        return 0;
    if (mapa[lpos][cpos] != '#')
        return 0;
    
    mapa[lpos][cpos] = 'x';
    mostrar(mapa);

    int total = queimar(mapa, lpos, cpos - 1) +
                queimar(mapa, lpos - 1, cpos) +
                queimar(mapa, lpos, cpos + 1) +
                queimar(mapa, lpos + 1, cpos);

    mapa[lpos][cpos] = '*';
    mostrar(mapa);

    return total + 1;
}

int main() {
    vector<string> mapa;
    ifstream arq("input.txt");
    int nl { }, nc { }, li { }, ci { };
    arq >> nl >> nc >> li >> ci;
    for(int i = 0; i < nl; i++) {
        string line;
        arq >> line;
        mapa.push_back(line);
    }

    cout << queimar(mapa, li, ci) << endl;
    //mostrar(mapa);

}