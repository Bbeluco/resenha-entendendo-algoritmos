#include <iostream>
#include <string>
#include <map>
#include <set>

using CoberturaT = std::set<std::string>;
using EstacoesT = std::map<std::string, CoberturaT>;

CoberturaT operator & (const CoberturaT&, const CoberturaT&);
void operator -= (CoberturaT&, const CoberturaT&);

void popula_estacoes(EstacoesT& estacoes) {
    estacoes.insert({ "kone", {"id", "nv", "ut"} });
	estacoes.insert({ "ktwo", {"wa", "id", "mt" } });
	estacoes.insert({ "kthree", {"or", "nv", "ca" } });
	estacoes.insert({ "kfour", {"nv", "ut" } });
	estacoes.insert({ "kfive", {"ca", "az" } });
}

int main() {
    CoberturaT estacoes_necessarias({ "mt", "wa", "or", "id", "nv", "ut", "ca", "az" });

    EstacoesT estacoes = {};
    popula_estacoes(estacoes);

    CoberturaT estacoes_finais{};
    std::string melhor_estacao{};

    while(!estacoes_necessarias.empty()) {
        CoberturaT estados_cobertos{};

        for(auto& i : estacoes) {
            CoberturaT cobertura = i.second & estacoes_necessarias;
            if(estados_cobertos.size() < cobertura.size()) {
                melhor_estacao = i.first;
                estados_cobertos = cobertura;
            }
        }

        estacoes_necessarias -= estados_cobertos;
        estacoes_finais.insert(melhor_estacao);
    }

    for (const auto& i : estacoes_finais) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

CoberturaT operator & (const CoberturaT& a, const CoberturaT& b) {
    CoberturaT result;
    for (const auto& i : a)
        for (const auto& j : b)
            if (i == j)
                result.insert(i);
    return result;
}

void operator -= (CoberturaT& a, const CoberturaT&b) {
    for(auto j = b.begin(); j != b.end(); ++j) {
        for(auto i = a.begin(); i != a.end();) {
            if(*i == *j) {
                i = a.erase(i);
            } else {
                ++i;
            }
        }
    }
}