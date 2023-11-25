Coloração dos Vertices

. Para cada vértice v da permutação P, tomado na ordem de P, atribua a ele a menor
cor disponível. Uma cor c é dita disponível se c ∈ C e nenhum vizinho de v possui
cor c. Caso não haja cor disponível, "crie"uma cor nova acrescentando mais uma
cor a C e atribua a nova cor a v.

A coloração de um grafo
é gulosa se, para cada vértice v de cor c, houver vizinhos de todas as cores menores que c.
E é essa a estratégia que iremos implementar.


Caso a coloração não seja uma coloração gulosa sua saída deve ser 0. Caso contrário,
imprima 1 seguido da permutação dos vértices utilizada. Em caso de empate na classe de
cor, os vértices devem ser ordenados pelo rótulo.
