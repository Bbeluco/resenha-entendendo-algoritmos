# Algoritmo K-Vizinhos mais proximos

A ideia desse algoritmo eh tentar encontrar quem eh meu elemento me baseando nos vizinhos dele, por exemplo suponha que voce tem que descobrir se um numero eh par ou impar. Voce consegue descrever se o numero eh par ou impar apenas pelo padrao dos vizinhos?

[1,3,X,7,9]
[2,4,X,8,10]

Obvio que esse exemplo que coloquei eh possivel ate mesmo saber qual valor que eh considerado o "X", mas o intuito do algoritmo K-Vizinhos mais proximo eh tentar descrever a **Caracteristica** do elemento baseando-se em seus vizinhos mais proximos.

Em suma eh possivel fazer 2 coisas com esse algortimo

1. Classificacao = Classificar a proximidade entre k elementos
2. Regressao = Advinhar qual a tendencia de um determinado valor

No exemplo 2 podemos imaginar a questao de avaliacoes, suponha que temos 5 pessoas proximas e cada ela da uma nota para um filme.

|Pessoa |Nota | 
|-------|-----|
|A      |5    |
|B      |4    |
|C 	    |4    |
|D 	    |5    |
|E 	    |3    |

A media de nota das pessoas da tabela acima eh 4,2. Logo, eh possivel presumir que se adicionarmos uma sexta pessoa neste grupo que tenha gostos parecidos a nota que ela dara para o filme deva seguir a tendencia da media

A ideia de K-Vizinhos tambem pode ser utilizada no aprendizado de maquinas.
A etapa de treinar a maquina (Quando falamos de imagens por exemplo) eh justamente falar para ela como um numero 7 se parece por exemplo. Dado as caracteristicas do numero (como linhas, angulos e curvas que o descrevem) eh possivel fazer com que a maquina entenda que tudo aquilo que parecer com a escrita no numero ha uma possibilidade X% de ser ele.