#include <iostream>
#include <sstream>
#include "../include/vertice.hpp"
#include "../include/ordenacao.hpp"
#include "../include/aresta.hpp"



using std::cout;
using std::cin;


bool verficaColoracaoGulosa(Vertice *v, Aresta *a, int n) {

    for (int i = 0; i < n; i++)
    {
        int pos_aresta = v[i].getNum();

        if(v[i].getCor() == 1) continue;

        for (int j = 1; j < v[i].getCor(); j++)
        {
            if(a[pos_aresta].cor_vizinhos[j] == 0) {
                return false;
            }
        }
    }  

    return true;

};



void imprimirVetor(Vertice * v, int n) {

    for (int i = 0; i < n; i++)
    {
        cout << v[i].getNum() << " ";
    }
    cout << std::endl;

};


int main(int argc,char ** argv){

    int n, m, v, cor;

    char c;

    cin >> c >> n;

    int cores[n];

    Vertice grafo[n];
    Aresta arestas[n];
    

    for (int i = 0; i < n; i++)
    {
        cin >> m;

        grafo[i].setNum(i);

        arestas[i].setVizinhos(m,n);

        for (int j = 0; j < m; j++)
        {
            cin >> v;
            arestas[i].adicionaVizinho(v);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cin >> cor;
        grafo[i].setCor(cor);
        cores[i] = cor;
        
    }

    for (int i = 0; i < n; i++)
    {
        arestas[i].constroiCoresVizinhos(cores);
        
    }

    if(verficaColoracaoGulosa(grafo, arestas, n)) {
        cout << "1 ";
    } else {
        cout << "0" << std::endl;
        return 0;
    }
    
    switch (c)
    {
    case 'b':
        /* bubble */
        bubbleSort(grafo, n);
        break;
    case 's':
        /* selection */
        selectionSort(grafo, n);
        break;
    case 'i':
        /* insertion */
        insertionSort(grafo, n);
        break;
    case 'q':
        /* quick */
        quickSort(grafo,0,n-1);
        break;
    case 'm':
        /* mergesort */
        mergeSort(grafo,0,n-1);
        break;
    case 'p':
        /* heapsort */
        heapSort(grafo, n);
        break;
    case 'y':
        countingSortByColor(grafo, n, n);
        break;
    
    default:
        break;
    }

    imprimirVetor(grafo, n);
   
    return 0;
}