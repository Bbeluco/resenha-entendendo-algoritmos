#include <iostream>
#include <vector>

/*
    O script a seguir foi idealizado por mim enquanto lia o segundo exemplo
    de "dividir para conquistar (DC)" no capitulo 4.

    A ideia desse script eh somar o total de numeros que temos dentro do array
    Obviamente poderiamos fazer isso sem utilizar a forma recursiva, mas visando
    exercitar o conhecimento estarei fazendo dessa forma.
*/

int soma_array(std::vector<int>& arr) {
    if(arr.size() == 1) {
        return arr[0];
    }

    int soma{arr[arr.size() - 1]};
    arr.pop_back();
    return soma + soma_array(arr);
}

int main() {
    std::vector<int> numeros{ 1,2,3 };
    std::cout << "A soma do array eh: " << soma_array(numeros) << '\n';
    return 0;
}