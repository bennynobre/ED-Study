#include <iostream>

auto soma(auto a, auto b){
    return a + b;
}

int main(){
    
    std::cout << __cplusplus << std::endl;
    std::cout << soma(2, 3) << std::endl;
}