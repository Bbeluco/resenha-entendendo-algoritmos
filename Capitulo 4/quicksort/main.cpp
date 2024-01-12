#include <iostream>
#include <vector>

using VecInt = std::vector<int>;

void snapshot(const VecInt& arr) {
    for(int n : arr) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void swap(VecInt& arr, const int start, const int end) {
    int aux{ arr[start] };
    arr[start] = arr[end];
    arr[end] = aux;
}

int particao(VecInt& arr, const int start, const int end) {
    int i { start };
    for(int j{start}; j < end; ++j) {
        if(arr[j] <= arr[end]) {
            swap(arr, i++, j);
        }
    }

    return i;
}

void quicksort(VecInt& arr, const int start, const int end) {
    snapshot(arr);
    if(start >= end) return;
    int pivo{ particao(arr, start, end) };

    quicksort(arr, start, pivo - 1);
    quicksort(arr, pivo + 1, end);
}

int main() {
    VecInt numeros{50, 42, 8, 23, 74, 91, 13, 26, 66, 3};
    quicksort(numeros, 0, numeros.size());
    return 0;
}