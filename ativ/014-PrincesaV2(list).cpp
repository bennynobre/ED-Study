#include <iostream>
#include <list>

using namespace std;

void show(list<int>& row, int sword) {
    cout << "[ ";

    for(auto i = row.begin(); i != row.end(); i++) {
        if (*i > 0 && *i == sword)
            cout << *i << "> ";
        else if(*i < 0 && *i == (-sword))
            cout << "<" << *i << " ";
        else
            cout << *i << " ";
    }

    cout << "]" << endl;
}

void matar(list<int>& row, int sword) {
    auto i = row.begin();

    while(*i != sword)
        i++;

    if(i == row.end() && *i > 0)
        row.front();
    else if(i == row.begin() && *i < 0)
        row.pop_back();
    else if(*i > 0)
        row.remove(*next(i));
    else if(*i < 0)
        row.remove(*prev(i));
}

void inicializar(list<int>& row, int size, int signal) {
    for(int i = 0; i < size; i++) {
        row.push_back((i + 1) * signal);
        signal *= -1;
    }
}

int main() {
    int size {}, sword {}, signal {};

    cout << "Tell the number of challengers: ";
    cin >> size;

    cout << "Tell who's start with the sword";
    cin >> sword;

    cout << "Tell the signal: ";
    cin >> signal;

    list<int> row;

    inicializar(row, size, signal);
    show(row, sword);

    while(row.size() > 1){
        matar(row, sword);
        sword = (sword + 1) % row.size();
        show(row, sword);
    }
}