#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

/*
    A ideia do codigo abaixo eh aplicarmos a questao de k-vizinhos mais proximos de modo simplificado
    Criei 3 arrays de mesmo tamanho, definiremos esses tamanhos como ponto e atraves do teorema de pitagoras
    definiremos qual eh a menor distancia entre eles.
    
    Segundo as proprias notas do autor do livro, o recomendado eh na verdade nos utilizarmos a relacao de angulo dos cossenos
    pois eles nos trata um valor mais aproximado do que pitagoras, mas como estamos em uma fase introdutoria pit ja caira bem.
*/

using AfinidadeFilmesT = std::vector<int>;

double encontraDistancia(const AfinidadeFilmesT& iconita, const AfinidadeFilmesT& vizinho) {
    double distancia{};
    for(int i{0}; i < iconita.size(); ++i) {
        distancia += (iconita[i] - vizinho[i])*(iconita[i] - vizinho[i]);
    }

    return std::sqrt(distancia);
}

int main() {
    AfinidadeFilmesT priyanka{3,4,4,1,4};
    AfinidadeFilmesT justin{4,3,5,1,5};
    AfinidadeFilmesT morpheus{2,5,1,3,1};

    if(encontraDistancia(priyanka, justin) < encontraDistancia(priyanka, morpheus)) {
        std::cout << "Priyanka esta mais proxima de justin\n";
    } else {
        std::cout << "Priyanka esta mais proxima de morpheus\n";
    }

    return 0;
}