#include <iostream>
#include <string>
#include <vector>

std::vector<int> matchingStrings(std::vector<std::string> vConsulta, std::vector<std::string> vBusca) {

    std::vector<int> count(vBusca.size(), 0);

    for (int i = 0; i < (int) vBusca.size(); i++) {
        for (int j = 0; j < (int) vConsulta.size(); j++) {
            if (vConsulta[j] == vBusca[i]) {
                count[i]++;
            }
        }
    }
    return count;
}

int main() {

    int consulta {}, busca {};

    std::cin >> consulta;
    std::vector<std::string> vConsulta(consulta);
    for(int i = 0; i < consulta; i++) {
        std::cin >> vConsulta[i];
    }

    std::cin >> busca;
    std::vector<std::string> vBusca(busca);
    for(int i = 0; i < busca; i++) {
        std::cin >> vBusca[i];
    }

    std::vector<int> resultado = matchingStrings(vConsulta, vBusca);

    for(int i = 0; i < (int) resultado.size(); i++) {
        std::cout << resultado[i] << " ";      
    }
    std::cout << std::endl;

    return 0;
}