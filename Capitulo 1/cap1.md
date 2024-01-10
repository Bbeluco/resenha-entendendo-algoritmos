# Pesquisa binaria

*com a pesquisa binaria voce chuta um elememento intermediario e elimina metade dos numeros restantes a cada tentativa.*

**O problema**

Suponha que voce tem uma lista telefonica e deseja encontrar alguem que se chama Mauro, voce poderia ir do comeco da lista (ou seja, da letra A) ate encontrar a letra "M", ou podemos ir diretamente para o meio da lista telefonica e comecar de la a pesquisar pelo "M" (ja que sabemos que em ordem alfabetica o M esta adiante do meio da lista). Apos encontrar a primeira letra do nome, ai sim voce pode procurar por outras letras que compoe a palavra que voce esta esperando.

> Feito o caso acima, conseguimos reduzir bastante a area de pesquisa, o que antes precisariamos correr do inicio ate o M, podemos simplesmente ir ao mesmo local mas encurtando o caminho.

Outra forma de pensar nisso seria uma brincadeira de alto ou baixo. Vamos supor que voce escolhe um numero entre 0 e 10, e seu amigo precisa advinhar qual numero voce escolheu, ele tera apenas dicas se o numero que ele escolheu foi baixo ou foi alto.

Uma forma inteligente de se chegar ao resultado rapidamente eh chutando o numero 5, como temos uma **lista ordenada** e 5 seria o correspondente do meio, chutando este numero conseguiremos saber o que a primeira pessoa escolheu com no maximo mais 5 palpites.

A situacao descrita acima, eh o metodo que redes como o Facebook usam para encontrar rapidamente o usuario que as pessoas desejam.

# Notacao Big O

*Descreve o quao rapido um algoritmo eh em numero de operacoes quanto menor melhor*

Saberr big O eh importante pois conseguimos saber o tempo de execucao daquele determinado algoritmo. Se fossemos comparar pesquisa simples com pesquisa binaria teriamos o seguinte cenario

| Elementos      | Pesquisa Simples | Pesquisa Binaria      |
| ----------- | ----------- | ----------- |
| 100      | 100ms       | 7ms      |
| 10k   | 10000ms        | 14ms     |
| 1Bi   | 11 dias        | 30ms     |  

Perceba no exemplo da tabela acima como por mais que aumentamos a escala, nao necessariamente a solucao da pesquisa binaria aumenta de forma igual. Como a pesquisa binaria trabalha em uma escala logaritma sua progressao tambem se da em outro aspecto.

>Importante ressaltar que essa diferenca nao se da apenas nesse algoritmo, mas em qualquer coisa comparado com linear X log

**A notacao big O nao informa o tempo em segundos, e sim o numero de operacoes que sera executado. O exemplo da planilha acima eh considerado que uma pesquisa leva 1ms mas isso nao eh regra no mundo real**

Todos os calculos de big O sao dados em log na base 2.
- O(n) = tempo linear
- O(log N) = tempo logaritmico
- O(N * log N) = algoritmo rapido de ordenacao
- O(n^2) = algoritmo lento de ordenacao
- O(n!) = algoritmo mais lento de todos
- O(1) = tempo constante

Sempre que falamos em ciclos de exec em algoritmos estamos levando em conta a pior das hipoteses, supondo que termos que passar por todo array/tabela/hash para encontrar o valor desejado.
