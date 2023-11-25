# grafos-coloridos

O trabalho proposto, com objetivo de recordar fundamentos de desenvolvimento
em C/C++ e introduzir conceitos como TADs (Tipos Abstratos de Dados), se trata da
resolução verificação se um grafo pré-colorido foi colorido de maneira gulosa e a
aplicação dos conceitos e funções de ordenação. A verificação positiva do método
guloso ocorre se cada um do vértice possui pelo menos um vértice vizinho, com cada
cor inferior a sua própria. A ordenação foi definida por valor numérico da cor e em caso
de empate pelo número de vértice. Os dados são fornecidos no seguinte formato:

* Um caractere c para sinalizar qual método de ordenação será utilizado e um
inteiro c para sinalizar o número de vértices.
* – b: Método da bolha ou bubble sort.
* – s: Método da seleção ou selection sort.
* – i: Método da inserção ou insertion sort.
* – q: quicksort. – m: mergesort.
* – p: heapsort.
* – y: Meu próprio método Couting Sort adaptado.
* N linhas indicado a quantidade e quais vizinhos cada vértice possui.
* A última linha contém n inteiros indicando as cores de cada um dos vértices.


## Uso
 * make all
 * ./bin/main < teste1.in
