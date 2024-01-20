#include <map>
#include <string>
#include <iostream>
#include <limits>
#include <vector>

using VizinhoT = std::map<std::string, int>;
using DijsktraT = std::map<std::string, VizinhoT>;
using PaisT = std::map<std::string, std::string>;

bool foi_processado(std::vector<std::string>& vertices_processado, std::string vertice) {
    for(std::string v : vertices_processado) {
        if(v == vertice) {
            return true;
        }
    }
    return false;
}

std::string acho_vertice_custo_mais_baixo(std::vector<std::string>& vertices_processado, VizinhoT& custos) {
    int menor_custo{std::numeric_limits<int>::max()};
    std::string vertice{custos.begin()->first};
    bool encontrou{false};

    for(VizinhoT::iterator it = custos.begin(); it != custos.end(); ++it) {
        if(!foi_processado(vertices_processado, it->first) && it->second < menor_custo) {
            menor_custo = it->second;
            vertice = it->first;
            encontrou = true;
        }
    }

    if(!encontrou) {
        return "PARADA";
    }
    return vertice;
}

int main() {
    DijsktraT grafo{};

    //Nivel 1
    grafo["inicio"] = {};
    grafo["inicio"]["a"] = 6;
    grafo["inicio"]["b"] = 2;
    
    //Nivel 2
    grafo["a"] = {};
    grafo["a"]["fim"] = 1;

    grafo["b"] = {};
    grafo["b"]["a"] = 3;
    grafo["b"]["fim"] = 5;

    grafo["fim"] = {};

    //Custos
    VizinhoT custos{};

    custos["a"] = 6; //Agora eh 5
    custos["b"] = 2;
    custos["fim"] = std::numeric_limits<int>::max(); //A ideia seria colocar aqui um infinito mas como os valores sao baixos esse tambem vai valer

    //Pais
    PaisT pais{};
    pais["a"] = "inicio";
    pais["b"] = "inicio";
    pais["fim"] = "";

    std::vector<std::string> vertices_processados{};

    std::string nodo = acho_vertice_custo_mais_baixo(vertices_processados, custos);
    while(nodo != "PARADA") {
        int custo = custos[nodo];
        VizinhoT vizinhos = grafo[nodo];
        for(VizinhoT::iterator v = vizinhos.begin(); v != vizinhos.end(); ++v) {
            std::string chave{v->first};
            int novo_custo = custo + vizinhos[chave];
            if(custos[chave] > novo_custo) {
                custos[chave] = novo_custo;
                pais[chave] = nodo;
            }
        }
        vertices_processados.push_back(nodo);
        nodo = acho_vertice_custo_mais_baixo(vertices_processados, custos);
    }

    std::cout << "O custo final foi: " << custos["fim"] << '\n';
    std::cout << "O caminho mais curto eh:\n";
    for(PaisT::iterator it = pais.begin(); it != pais.end(); ++it) {
        std::cout << it->first << "\t|" << it->second << '\n';
    }
    std::cout << '\n';
    return 0;
}