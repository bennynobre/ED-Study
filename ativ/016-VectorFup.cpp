#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int lenght;
    int size;
    int * data;
};

Vector * constructor(int lenght) {
    Vector * vet = new (Vector);
    vet->data = new int [lenght];
    vet->size = 0;
    vet->lenght = lenght;

    return vet; 
}

void destructor(Vector * vector) {
    delete[] vector->data;
    delete[] vector;
}

void add(Vector * vector, int value) {
    if (vector->size < vector->lenght) {
        vector->data[vector->size] = value;
        vector->size++;
    }
}

string show(Vector * vector) {
    stringstream ss;
    ss << '[';

    for (int i = 0; i < vector->size; i++) {
        ss << " " << vector->data[i];
    }

    ss << " ]";

    return ss.str();
}

int main(){
    string line, cmd;
    int value {};
    Vector * vet = constructor(4);

    while(true) {
        getline(cin, line);
        stringstream ss(line);
        cin >> cmd;

        if(cmd == "end") {
            break;
        } else if(cmd == "remove"){
            ss >> value;

            if(vet != nullptr)
                destructor(vet);

            vet = constructor(value);
        } else if(cmd == "status"){
            cout << "Size: " << vet->size << " || length:" << vet->lenght << endl;
        } else if(cmd == "add"){
            while(ss >> value)
                add(vet, value);
        } else if (cmd == "show") {
            cout << show(vet) << endl;
        } else {
            cout << "Invalid Comand!" << endl;
        }
    }

    destructor(vet);
}