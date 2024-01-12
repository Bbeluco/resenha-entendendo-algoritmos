#include <iostream>
#include <vector>

/*
    Script de resposta para a pergunta 4.2
*/

int quantidade(std::vector<int>& arr) {
    if(arr.size() == 1) {
        return 1;
    }
    arr.pop_back();
    return 1 + quantidade(arr); 
}

int main() {
    std::vector<int> numeros{1,2,3,4,5,6,7,8,9,10};
    std::cout << "A quantidade de itens no array eh: "  << quantidade(numeros) << '\n';
    return 0;
}