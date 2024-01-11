#include <iostream>

void print_ate_zero(int n) {
    std::cout << n << '\n';
    if(n != 0) { // Caso base
        print_ate_zero(n-1); // Caso recursivo
    }
}


int main() {
    print_ate_zero(10);
    std::cout << "Fim da recursao\n";
    return 0;
}