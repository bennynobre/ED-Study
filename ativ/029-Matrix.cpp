#include <iostream>
#include <sstream>
#include <vector>



struct Pos {
    int l, c;
    Pos(int l, int c): l(l), c(c) {}

    bool operator==(Pos pos) { 
        return l == pos.l && c == pos.c; }

    bool operator!=(Pos pos) { 
        return l != pos.l || c != pos.c; }

    std::string str() { 
        std::stringstream ss;
        ss << "(" << l << ", " << c << ")";
        return ss.str(); }
};

std::ostream &operator<<(std::ostream &os, Pos pos) {
    return os << pos.str();
}

template <class T>
class matrix {
    int numeroLinhas{0}, numeroColunas{0};
    vector<vector<T>> data;

public:
    matrix(int numeroLinhas, int numeroColunas): 
        numeroLinhas(numeroLinhas), numeroColunas(numeroColunas), data(numeroLinhas, std::vector<T>(numeroColunas)) {
    } 

    matrix(int numeroLinhas, int numeroColunas, T def): 
        numeroLinhas(numeroLinhas), numeroColunas(numeroColunas), data(numeroLinhas, std::vector<T>(numeroColunas, def)) {
    } 

    int linhas() {  return numeroLinhas; }

    int colunas() { return numeroColunas; }

    T& at(Pos pos) { 
        return data[pos.l][pos.c]; 
    }

    T& operator[](Pos pos) { return at(pos); }

    std::vector<T> &operator[](int l) { return data[l]; }

    bool inside(Pos pos) { 
        return !(pos.l < 0 || pos.l >= numeroLinhas || pos.c < 0 || pos.c >= numeroColunas); 
    }

    bool is_value(Pos pos, T value) { 
        return inside(pos) && at(pos) == value; 
    }

    std::string str() {
        std::stringstream ss;
        for (int l = 0; l < numeroLinhas; l++) {
            for (int c = 0; c < numeroColunas; c++)
                ss << (c == 0 ? "" : " ") << data[l][c];
            ss << '\n';
        }
        return ss.str();
     }
};

template <>
std::string matrix<char>::str() { 
    std::stringstream ss;
    for (int l = 0; l < numeroLinhas; l++) {
        for (int c = 0; c < numeroColunas; c++)
            ss << data[l][c]; 
        ss << '\n';
    }
    return ss.str();
}

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m) {
    return os << m.str();
}

int main() {
    {
        matrix<int> m(3, 4, 5);
        std::cout << m;
    }
    {
        matrix<char> m(3, 4, 'a');
        std::cout << m;
    }
    {
        matrix<int> m(3, 4);
        m[0][0] = 1; 
        m[{2, 2}] = 2;
        std::cout << m;
        std::cout << m.inside({-1, 2}) << '\n';
        std::cout << m.is_value({2, 2}, 2) << '\n';
        std::cout << m.is_value({-1, 2}, 0) << '\n';
    }

}