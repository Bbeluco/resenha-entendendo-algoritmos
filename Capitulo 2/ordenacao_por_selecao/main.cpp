#include <vector>
#include <iostream>

/*
    Aqui eh um exemplo de ordenacao por selecao. Esse exemplo ele foge um pouco do convencional
    pois no modelo original devemos remover o item que testamos do array original. 
    Tanto que no livro o autor escreve a linha "novoArr.append(arr.pop(menor))"

    Como no C++ nao temos essa facilidade como no Python de remover um item no array idependente da posicao,
    optei por fazer o algoritmo funcionar de tras para frente. Dessa forma o item seria "descartado" tambem

    Mas a ideia principal aqui eh notar como devemos fazer varias vezes a mesma operacao para organizar um simples array
    isso de fato eh muito demorado e pode ser muito custoso criar o array auxiliar tambem (caso o array original seja muito grande).
*/

using VecInt = std::vector<int>;
VecInt ordenacao_por_selecao(const VecInt& numeros) {
    int j{numeros.size() - 1};
    VecInt aux;
    do{
        int menor{numeros[j]};
        for(int i{j}; i >= 0; --i) {
            if(numeros[i] < menor) {
                menor = numeros[i];
            }
        }
        aux.push_back(menor);
        --j;
    }while(j >= 0);

    return aux;
}

int main() {
    VecInt numeros{6,5,4,3,2,1};
    VecInt lista_ordenada{ ordenacao_por_selecao(numeros) };
    for(int n : lista_ordenada) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}