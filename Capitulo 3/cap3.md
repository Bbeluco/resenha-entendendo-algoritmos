# Recursao
Basicamente, o conceito de recursao eh muito simples vamos imaginar uma boneca russa, comecamos do topo e queremos chegar na menor boneca possivel os passos logicos que fariamos eh o seguinte:

```mermaid
graph LR
A[Olhe o que ha dentro da boneca russa] --> B(Nada! Fim do algoritmo)
A --> C[Uma boneca russa] --> A
```

Repare que de forma recursiva eu vou chamando outra boneca russa, ate chegar uma hora em que elas acabam e por consequencia o algoritmo tambem

Em linhas gerais, loops sao mais performaticos em alguns casos do que recursao, porem, entender recursao faz voce desenvolver melhor um raciocinio logico

# Pilha (Call stack)
A pilha tem esse nome devido ao seu comportamento, vamos supor que voce trabalhe em um restaurante e deseja empilhar pratos, como o restaurante eh enorme digamos que voce tenha mil pratos empilhados.

Caso no futuro voce adicione/remova um desses pratos, o caminho mais rapido e seguro de fazer isso eh mexer apenas no primeiro prato da pilha (contando de cima para baixo obviamente). Da mesma forma funciona nosso computador, esse modelo de pilha eh conhecido como **LIFO (last-in first-out)**

Deixo aqui uma imagem de modelo de como funciona a call stack, a imagem foi retirada do artigo *In-Depth Introduction to Call Stack in JavaScript. - JavaScript Jeep* (https://medium.com/swlh/in-depth-introduction-to-call-stack-in-javascript-a07b8513bcc3)

![call stack](https://miro.medium.com/v2/resize:fit:1100/format:webp/1*rJ2sh-q1deQGGGVG5gYyIQ.png)

exemplos de codigo sobre pilha pode ser encontrado em **Capitulo 3/recursao/fatorial.cpp** caso possua algum debugger sera melhor ainda para visualizar o fluxo do codigo

Um detalhe que nao pode ser negligenciado eh que **a pilha sempre ocupa memoria do computador**, entao colocar muitos itens nela pode fazer com que o programe fique pesado ou ate crashe (stackoverflow).

### Caso base X Caso recursivo
Caso base = Condicao de parada para a recursao
Caso recursivo = instrucao que chama a propria recursao novamente 