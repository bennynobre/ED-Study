#include <iostream>
#include <vector>
#include <list>

int main() {
    //inicializando
    {
        //vazioa
        std::vector<int> v;
        size_t v_size { v.size() };
        size_t v_capacity { v.capacity() };
        v.reserve(10);
        v_size = v.size();
        v_capacity = v.capacity();

        std::list<double> l;
    }
    {
        //definindo valores iniciais
        std::vector<int> v = {1, 2, 3};
        size_t v_size { v.size() };
        size_t v_capacity { v.capacity() };

        std::list<double> l = {1.1, 2.2, 3.3};
        size_t l_size { l.size() };
    }
    {
        //com 10 elementos 0
        std::vector<int> v(10, 0);
        size_t v_size { v.size() };
        size_t v_capacity { v.capacity() };

        std::list<double> l(10, 0.0);
        size_t l_size { l.size() };
    }
    {
        std::vector<int> v = {1, 5, 4, 6, 7};
        std::list<int> l(v.begin(), v.end());
    }

    //adicionando
    {   
        /*
        push_back no vector irá adicionar no fim do vetor e quando
        o espaço acabar ele irá dobrar o tamanho e copiar os elementos
        -> Como o vector não existe push_front, usamos o insert para
        adicionar elementos no começo, e ele tem a operação de dar 
        saltos dentro do vetor usando o "+2" por exemplo.
        */
        std::vector<std::string> cores = {"azul", "amarelo"};
        cores.push_back("vermelho");
        size_t cores_size { cores.size() };
        size_t cores_capacity { cores.capacity() };
        cores.push_back("laranja");

        cores.insert(cores.begin(), "preto");
        cores.insert(cores.begin() +2, "dourado");

        /*
        Na lista assim como no vector temos o push_backa, que irá
        funcionar de uma maneira um pouco diferente pois ele não
        dobra de tamanho ele acrescenta 1 por 1, e também temos
        o push_front que como o nome diz insere no começo da lista.
        para darmos saltos não podemos simplesmente utilizar o operador
        "+", então se utiliza o next para retornar um iterador que anda
        x elementos a frente.a
        */
        std::list<std::string> nomes = { "Ana", "Bia", "Carlos"};
        nomes.push_back("David");
        nomes.push_back("Eliane");
        
        nomes.push_front("Mara");
        nomes.push_front("Xuxa");

        nomes.insert(nomes.begin(), "Sasha");
        nomes.insert(std::next(nomes.begin(), 2), "Zezinho");

    }

    //acessando
    {
        std::vector<int> v = {1, 2, 3, 4, 5};

        std::cout << v.front() << " " << v.back() << std::endl;
        std::cout << v[1] << std::endl;
        std::cout << v.at(2) << std::endl; //seguro porém mais lento
        std::cout << *(v.begin() + 2) << std::endl; //feio

        std::list<int> l = {1, 2, 3, 4, 5};
        std::cout << l.front() << " " << l.back() << std::endl;
        //std::cout << l.at(0) << std::endl; ERRO
        std::cout << *(std::next(l.begin(), 2)) << '\n';
    }

    //removendo
    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        v.pop_back();
        v.erase(v.begin() + 1); //segundo
        v.erase(v.end() - 2); //penultimo

        std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        l.pop_back();
        l.pop_front();

        l.erase(std::next(l.begin())); //segundo
        l.erase(std::prev(l.end(), 2)); //penultimo
    }

    //percorrendo por COPIAA
    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for(auto elemento : v) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;

        std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (auto elemento : l) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl; 
    }

    //percorrendo por REFERENCIA
    {
        //igual pra vector ou list
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (auto &i : v) {
            i *= 2;
        }
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //percorrendo por índice
    {
        //só funciona pra vector
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < (int) v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    //percorrendo por iterador
    {
        //igual pra vector ou list
        std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (auto it = l.begin(); it != l.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    //removendo todos os impares
    {
        //igual para vector ou list
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (auto it = v.begin(); it != v.end();) {
            if (*it % 2 == 1) {
                it = v.erase(it);
            } else {
                it++;
            }
        }
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //percorrendo ao contrário
    {
      //igual para vector ou list
      //com vector dá pra fazer por indice
      std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      for (auto it = v.end(); it != v.begin();) {
          it--;
          std::cout << *it << " ";
      }  
      std::cout << std::endl;

      //ou com rbegin
      std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      for (auto it = l.rbegin(); it != l.rend(); it++) {
          std::cout << *it << " ";
      }
    }
}