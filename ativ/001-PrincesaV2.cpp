#include <iostream>
#include <vector>


std::ostream& operator<<(std::ostream& os, const std::vector<int>& row) {
    os << "[";

    for(int i = 0; i < (int) row.size(); i++) {
        os << row[i];
        if (i != (int) row.size() -1)
            os << ", ";
    }
;
    os << "]";
    return os;
}

void init(std::vector<int>& row, int signal, int size) {
    if(signal < 0) {
        int count = 1;

        for (int i = 0; i < size; i++) {
            if (count % 2 == 0)
                row.push_back(count);
            else
                row.push_back(-count);

            count++;
        }
    } else {
        int count = 1;

        for (int i = 0; i < size; i++) {
            if ((count%2) == 0)
                row.push_back(-count);
            else
                row.push_back(count);

            count++;
        }
    }
}

void show(std::vector<int>& row, int sword) {
    std::cout << "[";

    for (int i = 0; i < (int) row.size(); i++) {
        if (i == sword && row[i] > 0)
            std::cout << row[i] << ">";
        else if (i == sword && row[i] < 0)
            std::cout << "<" << row[i];
        else
            std::cout << row[i];
        if(i != (int) row.size() -1)
            std::cout << ", ";
    }

    std::cout << " ]" << std::endl; 
}

void kill(std::vector<int>& row, int pos) {
    row.erase(row.begin() + pos);
}

int main() 
{
    int size{}, pos{}, signal{};

    std::cout << "Say the size: ";
    std::cin >> size;

    std::cout << "Say who's start with the sword: ";
    std::cin >> pos;

    std::cout << "Say the signal: ";
    std::cin >> signal;

    std::vector<int> row;
    init(row, signal, size);
    pos--;

    while((int) row.size() != 1) {
        if(pos < 0)
            pos = (int)row.size() - 1;

        show(row, pos);
        pos = pos % (int)row.size();

        if(row[pos] < 0) {
            if (pos - 1 < 0) {
                kill(row, (int)row.size() - 1);
                pos = (int)row.size() - 1;
            } else {
                pos--;
                kill(row, pos);
                pos--;
                pos = pos % (int)row.size();
            }
        } else {
            pos++;
            pos = pos % (int)row.size();
            kill(row, pos);    
        }
    }
    std::cout << row;
}