#include <iostream>
#include <vector>

/*
    Script de resposta para a pergunta 4.3
*/

int maior(std::vector<int> arr) {
    if(arr.size() == 1) {
        return arr[0];
    }
    int maior_atual{arr[arr.size() - 1]};
    arr.pop_back();
    int maior_anterior{ maior(arr) };
    return maior_atual > maior_anterior ? maior_atual : maior_anterior;
}

int main() {
    std::vector<int> numeros{1,2,3,4,5,6,7,8,9,10};
    std::cout << "O maior valor eh: " << maior(numeros) << '\n';
    return 0;
}