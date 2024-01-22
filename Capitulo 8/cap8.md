# Algoritmos gulosos (algoritmo de aproximacao)

> Algoritmo util para qualquer uma solucao aproximada quando a solucao exata se mostrar muito custosa (tempo/recurso) para se calcular

Esse algoritmo baseia-se em cada etapa tentar encontrar a solucao ideal. A soma das solucoes ideias de cada etapa resulta na solucao ideal global.

A solucao funciona geralmente em 2 etapas

1. Escolha o item que mais se adequa a sua etapa
2. Repita isso para o 2, 3, 4, 5 item e etc.

A proposta desse tipo de algoritmo nao eh alcancar o valor exato para sua situacao e sim achar um valor aproximado o mais rapido possivel. No livro a um exemplo onde esse tipo de algoritmo nao funciona.

Imagine que voce tem uma bolsa que consegue carregar 16 kilos. Voce tem 3 itens que eh capaz de levar e quer ganhar o maximo de dinheiro possivel nesses itens.

|Item 	 |Valor 	 | Peso | 
|--------|---------  | ----- | 
|Violao       |1,5k        | 6kg| 
|Notebook |2k        | 9kg | 
|Radio 	   |3k | 13kg |

Seguindo a logica do algoritmo guloso nosso primeiro passo vai ser encontrar o maximo de dinheiro que podemos ganhar **COM UM UNICO ITEM**

Nesse caso o item escolhido seria o "radio" pois ele nos garante 3k.

Repare que a soma "violao" + "notebook" nos daria 3,5k e ganhariamos mais dinheiro. Porem o algoritmo guloso nao tem como intuito chegar no valor exato, ele tenta chegar no valor mais proximo possivel (*as vezes acertando mas na maioria das vezes com uma margem de erro*)


### Conjuntos
Assim como na matematica, na programacao tambem temos o exato mesmo conceito de conjunto (que nada mais eh que uma lista sem valores repetidos). Como temos o mesmo conceito conseguimos fazer operacoes como: "Uniao", "Interseccao" e "Diferenca"
