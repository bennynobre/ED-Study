#include <iostream>
#include <sstream>


struct Vector {
    int lenght {4};
    int size {0};
    int * data {nullptr};

    Vector(int lenght) : lenght(lenght) {
        this->data = new int[lenght];
    }

    ~Vector() {
        delete[] this->data;
    }

    void operator = (const Vector& other){
        this->lenght = other.lenght;
        this->size = other.size;

        if(this->data != nullptr) {
            delete[] this->data;
        }

        this->data = new int[other.lenght];

        for(int i = 0; i < other.lenght; i++) {
            this->data[i] = other.data[i];
        }
    }

    Vector(Vector& other) {
        *this = other;
    }

    void adicionar(int valor) {
        if(this->size < this->lenght) {
            this->data[this->size] = valor;
            size++;
        }
    }

    friend std::ostream& operator<<(std::ostream &os, Vector vector){
        os << "[ ";

        for(int i = 0; i < vector.size; i++)
            os << vector.data[i] << " ";

        os << "]";
        
        return os;
    }
};

int main(){
    std::string line, cmd;
    int valor{};
    Vector vet(4);

    while(true){
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::cin >> cmd;

        if(cmd == "end") {
            break;
        } else if (cmd == "remove") {
            ss >> valor;
            vet = Vector(valor);
        } else if (cmd == "status") {
            std::cout << "Size: " << vet.size << " || Lenght: " << vet.lenght << std::endl;
        } else if (cmd == "add") {
            while(ss >> valor)
                vet.adicionar(valor);
        } else if(cmd == "show") {
            std::cout << vet << std::endl;
        } else {
            std::cout << "Invalid Comand!" << std::endl;
        }
    }
}