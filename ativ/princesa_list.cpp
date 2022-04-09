#include <iostream>
#include <list>

int main(){
    
        std::list<int> lista = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::cout << "Declare a posição do primeiro guerreiro" << std::endl;
    
        int x{};
        std::cin >> x;
    
        while(true) {
            if(lista.size() == 1) {
                std::cout << "O guerreiro " << lista.front() << " venceu!" << std::endl;
                break;
            }
    
            x++;
            if(x == (int)lista.size()) {
                x = 0;
            }
    
            for(int i = 0; i < (int)lista.size(); i++) {
                std::cout << lista.front() << " ";
                lista.pop_front();
            }
    
            std::cout << std::endl;
        }
    
}