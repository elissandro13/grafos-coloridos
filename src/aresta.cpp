#include <iostream>
#include "../include/aresta.hpp"


Aresta::Aresta() {
    num_vizinhos = 0;
    vizinhos = nullptr; 
    cor_vizinhos = nullptr;
};

void Aresta::setVizinhos(int qtd_viznhos, int num_cores) {
    vizinhos = new int[qtd_viznhos+1];
    cor_vizinhos = new int[num_cores+1];

    for (int i = 0; i < qtd_viznhos; i++)
    {
        vizinhos[i] = -1;
        
    }

    for (int i = 0; i <= num_cores; i++)    
    {
       
        cor_vizinhos[i] = 0;
    }
    
};

void Aresta::adicionaVizinho(int n) {
    vizinhos[num_vizinhos] = n;
    num_vizinhos++;
};

void Aresta::constroiCoresVizinhos(int *vetor_cores) {
    for (int i = 0; i < num_vizinhos; i++)
    {
        if(vizinhos[i] == -1) {
            std::cout << "Erro Vizinho de Valor -1" << std::endl;
            return;
        }
        //std::cout << "Olha a cor" << vetor_cores[vizinhos[i]] << std::endl;
        cor_vizinhos[vetor_cores[vizinhos[i]]]++;

        
    }
    
}

Aresta::~Aresta() {
    if (vizinhos != nullptr) {
        delete[] vizinhos;
        vizinhos = nullptr;
    }
    if (cor_vizinhos != nullptr) {
        delete[] cor_vizinhos;
        cor_vizinhos = nullptr;
    }
}