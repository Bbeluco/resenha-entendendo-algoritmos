#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

/*
    O codigo abaixo eh uma representacao de como grafos fazem sua pesquisa.
    1 -> Enfileire seus grafos (nesse caso so tem um mas poderia ter mais)
    2 -> Retire o primeiro item da lista (no codigo tem uma logica pra imitar isso pq nao conheco nenhum popfirst em c++)
    3 -> Pesquise por niveis (Queremos sempre encontrar o menor caminho, por isso estamos pesquisando por niveis)


*/

using GrafoT = std::map<std::string, std::vector<std::string>>;
using NiveisT = std::vector<std::vector<std::string>>;

class Grafo {
public:
    Grafo() {
        populateGrafo();
        setupNiveis();
    }

    NiveisT getNiveis() { return m_niveis; }
    GrafoT getGrafo() { return m_grafo; }

private:
    GrafoT m_grafo{};
    NiveisT m_niveis{};
    void populateGrafo() {
        m_grafo["Bruno"] = {"Alice", "Bob", "Claire"};
        m_grafo["Bruno"] = {"Alice", "Bob", "Claire"};
        m_grafo["Bob"] = {"Anuj", "Peggy"};
        m_grafo["Alice"] = {"Peggy"};
        m_grafo["Claire"] = {"Thom", "Jonny"};
        m_grafo["Anuj"] = {};
        m_grafo["Peggy"] = {};
        m_grafo["Jonny"] = {};
        m_grafo["Thom"] = {};
    }

    void setupNiveis() {
        std::vector<std::string> nivel1{"Bruno"};
        m_niveis.push_back(nivel1);

        std::vector<std::string> nivel2{"Bob", "Alice", "Claire"};
        m_niveis.push_back(nivel2);

        std::vector<std::string> nivel3{"Anuj", "Peggy", "Jonny", "Thom"};
    }
};

int main() {
    Grafo grafo;
    std::vector<GrafoT> fila_de_pesquisa{};
    fila_de_pesquisa.push_back(grafo.getGrafo());

    while(fila_de_pesquisa.size() > 0) {
        GrafoT pessoa{fila_de_pesquisa[fila_de_pesquisa.size() - 1]};
        fila_de_pesquisa[fila_de_pesquisa.size() - 1] = fila_de_pesquisa[0];
        fila_de_pesquisa[0] = pessoa;

        std::vector<std::string> p_verificadas{};

        for(std::vector<std::string> nivel : grafo.getNiveis()) {
            for(std::string vizinho : nivel) {
                for(std::string p : pessoa[vizinho]) {
                    if(std::find(p_verificadas.begin(), p_verificadas.end(), p) != p_verificadas.end()) {
                        continue;
                    }
                    if(p == "Jonny") {
                        std::cout << "Encontramos Jonny\n";
                        return 0;
                    }
                    p_verificadas.push_back(p);
                }
            }
        }

        fila_de_pesquisa.pop_back();
    }

    std::cout << "Ninguem conhece essa pessoa\n";
    return 0;
}