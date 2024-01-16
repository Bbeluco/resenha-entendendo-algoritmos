/*
    O script abaixo replica o que seria o comportamento de um algoritmo quicksort
    No algoritmo original, precisariamos seguir os passos descritos em cap4.md

    A diferenca que temos aqui eh que na realidade nao ah a existencia de items para o pivo ficar ao meio
    na realidade ja fazemos a verificacao e trocamos o valor atual com o menor valor possivel da lista

    Para ser honesto, medi o Big(O) do codigo e o nivel de ciclos foi exatamente igual a um ciclo de quicksort
    nao consigo dizer se esse codigo pode ser considerado um quicksort "raiz" (pelo fato de nao colocarmos o pivo entre 2 arrays)
    porem eh possivel dizer sim que temos o mesmo nivel de Big(O) (O(n))

    Sou o Bruno do futuro e vim colocar alguns apontamos sobre o codigo

    AO QUE PARECE minha solucao na realidade minha solucao tem O(n2) 
    tendo em vista que ela precisa escolher o pivo e comparar ele com a lista inteira
*/

#include <iostream>
#include <vector>

using VecInt = std::vector<int>;

void snapshot(const VecInt& arr) {
    for(int n : arr) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void swap(VecInt& arr, const int a, const int b) {
    int aux{ arr[a] };
    arr[a] = arr[b];
    arr[b] = aux;
}

void quicksort(VecInt& arr, const int start, const int end) {
    snapshot(arr);
    int pivo{ arr[(start+end)/2] };
    int pointeiro_esquerda{start};
    int pointeiro_direita{end};

    while(pointeiro_esquerda <= pointeiro_direita) {
        while(pivo > arr[pointeiro_esquerda]) { pointeiro_esquerda++; }
        while(arr[pointeiro_direita] > pivo) { pointeiro_direita--; }

        if(pointeiro_esquerda <= pointeiro_direita) {
            swap(arr, pointeiro_esquerda, pointeiro_direita);
            ++pointeiro_esquerda;
            --pointeiro_direita;
        }
    }

    if(start < pointeiro_direita) { quicksort(arr, start, pointeiro_direita); }
    if(pointeiro_esquerda < end) { quicksort(arr, pointeiro_esquerda, end); }
}

int main() {
    VecInt numeros{4, 2, 8, 7, 1, 5, 3, 6};
    quicksort(numeros, 0, numeros.size() - 1);
    std::cout << '\n';
    for(int n : numeros) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}