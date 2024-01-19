#include <vector>
#include <map>
#include <string>

/*
    O exemplo do codigo abaixo se baseia na explicacao do autor na etapa de
    "Implementacao de grafo".

    Eh interessante ressaltar como a chave do grafo (Ex: grafo["Bruno"])
    deve conter apenas elementos que os grafos estao apontando

    Por exemplo, no livro Bruno -> Alice -> Peggy. Se voce reparar o correto foi
    colocar Alice somente apontando para Peggy e nao para Bruno e Peggy

    Isso fica ainda mais evidente se notar que os nomes no final sao declarados com um vetor vazio
*/

int main() {
    std::map<std::string, std::vector<std::string>> grafo{};
    grafo["Bruno"] = {"Alice", "Bob", "Claire"};
    grafo["Bob"] = {"Anuj", "Peggy"};
    grafo["Alice"] = {"Peggy"};
    grafo["Claire"] = {"Thom", "Jonny"};
    grafo["Anuj"] = {};
    grafo["Peggy"] = {};
    grafo["Jonny"] = {};
    grafo["Thom"] = {};

    return 0;
}