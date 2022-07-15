#include <iostream>
#include <vector>
#include <list>


void show(std::list<int>& row, int sword) {
    std::cout << "[ ";

    for(auto i = row.begin(); i != row.end(); i++) {
        if (*i == sword)
            std::cout << *i << "> ";
        else
            std::cout << *i << " ";
    }

    std::cout << "]" << std::endl;
}

void kill(std::list<int>& row, int sword) {
    auto i = row.begin();

    while(*i != sword)
        i++;

    if(i == row.end())
        row.front();
    else
        row.remove(*next(i));
}

int main() {
    int size {}, sword {};

    std::cout << "Tell the number of challengers: ";
    std::cin >> size;

    std::cout << "Tell who's start with the sword: ";
    std::cin >> sword;

    std::list<int> row;

    for(int i = 0; i < size; i++)
        row.push_back(i + 1);

    int aux = row.size();

    while(aux > 1) {
        show(row, sword);
        kill(row, sword);
        sword = (sword + 1) % size;
        aux--;
    }

    show(row, sword);
}