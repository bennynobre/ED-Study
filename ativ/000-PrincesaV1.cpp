#include <iostream>
#include <vector>


void mostrar(std::vector<int> row, int sword) {
    std::cout << "[";
    bool VerifyBeforeFirst = true;

    for(int i = 0; i < row.size(); i++) {
        if(VerifyBeforeFirst)
            VerifyBeforeFirst = false;
        else
            std::cout << " ";
        
        if(row[i] == sword)
            std::cout << row[i] << ">";
        else
            std::cout << row[i];
    }

    std::cout << "]" << std::endl;
}

void kill(std::vector<int>& row, int sword) {
    row.erase(row.begin() + sword);
}

int nextSword(std::vector<int>& row, int alive) {
    return *row.begin() + 1;
}

int main() {
    int sword {};
    int size {};

    std::cout << "Say the size: ";
    std::cin >> size;

    std::cout << "Who's start with the sword: ";
    std::cin >> sword;

    std::vector<int> row;

    for(int i = 0; i < size; i++)
        row.push_back(i + 1);

    mostrar(row, sword);

    while(row.size() > 1) {
        kill(row, sword);
        sword = (sword + 1) % row.size();
        mostrar(row, sword);
    }
}