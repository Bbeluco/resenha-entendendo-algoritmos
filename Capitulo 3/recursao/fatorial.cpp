#include <iostream>

/*
    Neste modelo eh possivel ver muito bem a pilha sendo formada
    O fluxo abaixo eh o seguinte:

    1. Enquanto fatorial != 1 continue chamando fatorial
    2. Multiplique esse valor com n (mesma coisa de dizer fatorial() + 1)

    Devido ao modelo de pilha, vamos o mais fundo possivel na funcao 
    e gracas a condicao de parada (n == 1) comecamos a fazer o caminho inverso
    devolvendo o que foi gerado do passo anterior * n

    O codigo pode parecer um pouco contraintuitivo e ate mesmo magico,
    mas basta perceber que eh o retorno passado * n, e por isso a saida eh mostrada

*/

int fatorial(int n) {
    if(n == 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

int main() {
    std::cout << "5! = " << fatorial(5) << '\n';
    return 0;
}