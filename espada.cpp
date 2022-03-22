#include <iostream>
#include <vector>


int main(){

    std::vector<int> vetor{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Declare o primeiro guerreiro" << std::endl;

    int x{};
    std::cin >> x;

    while(true) {
        if(vetor.size() == 1) {
            std::cout << "O guerreiro " << vetor[0] << " venceu!" << std::endl;
            break;
        }

        x++;
        if((unsigned)x == vetor.size()) {
            x = 0;
        }

        for(int i = 0; (unsigned)i < vetor.size(); i++) {
            std::cout << vetor[i] << " ";
        }

        vetor.erase(vetor.begin() + x);

        if((unsigned)x == vetor.size()) {
            x = 0;
        }

        std::cout << std::endl;
    }

}