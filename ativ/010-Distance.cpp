#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

const char EMPTY = '.';

struct Problem {
    std::string data;
    int limit;
    std::vector<int> result;

    Problem(std::string data, int limit) : data(data), limit(limit) {
        this->data = data;
        this->limit = limit;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == EMPTY) {
                this->result.push_back(i);
            }
        }
    }

    bool fit(int index, char value) {
        if (index < 0 || index >= data.size()) {
            return false;
        }
        if (data[index] == EMPTY) {
            return true;
        }
        return data[index] == value;
    }

    bool solve(int hindex) {
        if (hindex >= result.size()) {
            return true;
        }
        int index = result[hindex];
        for (char value = '0'; value <= '9'; value++) {
            if (fit(index, value)) {
                data[index] = value;
                if (solve(hindex + 1)) {
                    return true;
                }
            }
        }
        data[index] = EMPTY;
        return false;
    }
};

int main () {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        std::string data;
        int limit;
        in >> data >> limit;
        Problem problem(data, limit);
        problem.solve(0);
        out << problem.data << std::endl;
    }
    return 0;
}