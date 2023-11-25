#include "../include/heap.hpp"
#include "../include/ordenacao.hpp"


Heap::Heap(int maxsize) {
    this->tamanho = 0;
    this->data = new Vertice[maxsize];

};

Heap::~Heap() {
    delete[] data;
};

void Heap::Inserir(Vertice x) {

    data[tamanho].setCor(x.getCor());
    data[tamanho].setNum(x.getNum());

    int i = tamanho;
    int p = GetAncestral(i);

    while(comparaMenor(&data[i] , &data[p])) {

        swap(&data[i], &data[p]);

        i = p;
        p = GetAncestral(i);
    }


    tamanho++;

};

Vertice Heap::Remover() {
    
    Vertice x;
    if(!Vazio()) {
        x = data[0];
        data[0] = data[tamanho-1];
        tamanho--;

        int i = 0;
        int esquerda = GetSucessorEsq(i);
        int direita = GetSucessorDir(i);

        int s = 0;

        if(esquerda < tamanho && direita < tamanho) {
            s = comparaMenor(&data[esquerda], &data[direita]) ? esquerda : direita;
        }
        else if (esquerda < tamanho) {
            s = esquerda;
        } else {
            return x;
        }


        while(comparaMaior(&data[i], &data[s]) && s <= tamanho) {
                
                //std::cout << "Trocando os n " << i << " " << s << std::endl;
                swap(&data[i], &data[s]);

                i = s;
                esquerda = GetSucessorEsq(i);
                direita = GetSucessorDir(i);

                if(esquerda < tamanho && direita < tamanho) {
                    s = comparaMenor(&data[esquerda], &data[direita]) ? esquerda : direita;
                }
                else if (esquerda < tamanho) {
                    s = esquerda;
                } else {
                    return x;
                }
        }


    
        return x;
    }
    return data[0];    

};

//Retorna true caso o heap esteja vazio, false caso contrário.

bool Heap::Vazio() {
    return this->tamanho == 0;
};


int Heap::GetAncestral(int posicao) {

    return (posicao-1)/2;

};

int Heap::GetSucessorEsq(int posicao) {

    return 2 * posicao + 1;

};

int Heap::GetSucessorDir(int posicao) {

    return 2 * posicao + 2;

};
