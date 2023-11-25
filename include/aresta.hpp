#ifndef ARESTA_HPP
#define ARESTA_HPP

class Aresta {

    public:
        Aresta();

        int * vizinhos;
        int * cor_vizinhos;

        int num_vizinhos;

        void setVizinhos(int qtd_viznhos, int num_cores);

        void adicionaVizinho(int n);

        void constroiCoresVizinhos(int *vetor_cores);

        ~Aresta();

    

    

};


#endif
