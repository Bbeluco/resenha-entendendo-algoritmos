#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main() {
    std::string palavraA {"fish"};
    std::string palavraB {"fosh"};

    const size_t& tamanhoA {palavraA.size()};
    const size_t& tamanhoB {palavraB.size()};

    size_t** tabela = new size_t* [tamanhoA];
    for(size_t l{0}; l < tamanhoA; ++l) {
        tabela[l] = new size_t[tamanhoB]{};
    }

    for(size_t i{0}; i < tamanhoA; ++i) {
        for(size_t j{0}; j < tamanhoB; ++j) {
            if(palavraA[i] == palavraB[j]) {
                if(i > 0 && j > 0) {
                    tabela[i][j] = tabela[i-1][j-1] + 1;
                } else {
                    tabela[i][j] = 1;
                }
            } else {
                if(i == 0 && j > 0) {
                    tabela[i][j] = tabela[i][j-1];
                } else if(i > 0 && j == 0) {
                    tabela[i][j] = tabela[i-1][j];
                } else {
                    tabela[i][j] = std::max(tabela[i][j-1], tabela[i-1][j]);
                }
            }
        }
    }

    for (size_t i = 0; i < tamanhoA; ++i) {
		std::cout << "[ ";
		for (size_t j = 0; j < tamanhoB; ++j) {
            std::cout << tabela[i][j] << ' ';
        }
        std::cout << ']' << '\n';
	}

    return 0;
}