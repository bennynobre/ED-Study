#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

void show_matrix(std::vector<std::vector<char>> mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            std::cout << mat[i][j];
        }
        std::cout << std::endl;
    }
}

void tocar_fogo(std::vector<std::vector<char>> &mat, int l, int c){
    if(l < 0 || l >= mat.size() || c < 0 || c >= mat[l].size()){
        return;
    }
    if(mat[l][c] != '#'){
        return;
    }
    mat[l][c] = 'o';
    tocar_fogo(mat, l - 1, c - 1);
    tocar_fogo(mat, l - 1, c);
    tocar_fogo(mat, l - 1, c + 1);
    tocar_fogo(mat, l, c - 1);
    tocar_fogo(mat, l, c + 1);
    tocar_fogo(mat, l + 1, c - 1);
    tocar_fogo(mat, l + 1, c);
    tocar_fogo(mat, l + 1, c + 1);
}

int main () {
    int nl, nc, l, c;
    std::cin >> nl >> nc >> l >> c;
    std::vector<std::vector<char>> mat(nl, std::vector<char>(nc));
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            std::cin >> mat[i][j];
        }
    }
    tocar_fogo(mat, l, c);
    show_matrix(mat);
    return 0;
}