#include <iostream>
#include <vector>

void pesquisa_binaria(const std::vector<int>& numeros, int escolha) {
    int baixo{0};
    int alto{numeros.size() - 1};
    while(baixo <= alto) {
        int palpite{ (baixo + alto) / 2};
        if(numeros[palpite] == escolha) {
            std::cout << "A posicao do numero eh: " << palpite << '\n';
            return;
        }

        if(numeros[palpite] > escolha){
            alto = palpite - 1;
        } else if(numeros[palpite] < escolha) {
            baixo = palpite + 1;
        }
    }

    std::cout << "O numero escolhido nao existe na lista\n";
}

int main() {
    std::vector<int> numeros{1,2,3,4,5,6,7,8,9,10};
    int escolha{1};

    pesquisa_binaria(numeros, escolha);
    return 0;
}