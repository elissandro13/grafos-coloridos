#ifndef HEAP_HPP
#define HEAP_HPP

#include "vertice.hpp"
#include "ordenacao.hpp"

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Alteracoes no arquivo so podem ser feitas quando explicitadas
 */

class Heap {

    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(Vertice x);
        Vertice Remover();

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool Vazio();
        

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        

        int tamanho;
        Vertice* data;
};


#endif