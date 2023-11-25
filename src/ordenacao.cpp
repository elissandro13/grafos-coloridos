#include "../include/ordenacao.hpp"
#include "../include/heap.hpp"


//Deep Copy
void swap(Vertice * a, Vertice * b) {
    
    Vertice tmp;
    tmp.setCor(a->getCor());
    tmp.setNum(a->getNum());

    a->setCor(b->getCor());
    a->setNum(b->getNum());

    b->setCor(tmp.getCor());
    b->setNum(tmp.getNum());
}

// Comparação menor: Cor priridade 1, num prioridade 2
bool comparaMenor(Vertice * a, Vertice * b) {

    if(a->getCor() == b->getCor())
        return (a->getNum() < b->getNum());
    
    return (a->getCor() < b->getCor());

};

// Comparação maior: Cor priridade 1, num prioridade 2
bool comparaMaior(Vertice *a, Vertice *b) {

    if(a->getCor() == b->getCor())
        return (a->getNum() > b->getNum());
    
    return (a->getCor() > b->getCor());

};

void bubbleSort(Vertice *v, int n) {

    int i,j;

    // Flag para parar quando não houver mais trocas
    bool trocou;

    for (i = 0; i < n - 1; i++)
    {
        trocou = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if(comparaMaior(&v[j], &v[j+1])) {

                swap(&v[j], &v[j+1]);

                trocou = true;
            } 
        }
        
    }
    
    if(!trocou) return;

};



void selectionSort(Vertice *v, int n) {
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
 
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (comparaMenor(&v[j], &v[min_idx])) {
                min_idx = j;
            }
        }
 
        if (min_idx != i) {     

            swap(&v[min_idx], &v[i]);

        }
    }
};


void insertionSort(Vertice *v, int n) { 
    for (int i = 1; i < n; i++) { 
		
		int j = i;
	
		while (j > 0 && comparaMenor(&v[j], &v[j-1])) {

            swap(&v[j], &v[j-1]);

			j -= 1;
		}
	
	}	
};


int partition(Vertice *v, int menor, int maior)
{
  //Escolher o pivo
   
  Vertice pivo = v[maior];
  

  int i= menor-1;
   
  for(int j = menor;j <= maior; j++)
  {
    //Se o elemento é menor que o pivo
    if(comparaMenor(&v[j],&pivo))
    {
      //Aumenta index
      i++;
      swap(&v[i],&v[j]);
    }
  }

  swap(&v[i+1],&v[maior]);

  return (i+1);
}


void quickSort(Vertice *v, int menor,int maior) {

    if(menor < maior)
    {
    // Index do pivo

    int index = partition(v,menor,maior);     
    
    //Direita
    quickSort(v,menor,index-1);

    //Esquerda
    quickSort(v,index+1,maior);
    }

};

void merge(Vertice *v, int esq, int meio, int dir) {

    int tamVetAuxiliar1 = meio - esq + 1;
    int tamVetAuxiliar2 = dir - meio;

    Vertice vetEsq[tamVetAuxiliar1];
    Vertice vetDir[tamVetAuxiliar2];

    // Copiar dados para os vetores auxiliares

    for (int i = 0; i < tamVetAuxiliar1; i++)
    {
        vetEsq[i].setCor(v[esq + i].getCor());
        vetEsq[i].setNum(v[esq + i].getNum());
    }

    for (int j = 0; j < tamVetAuxiliar2; j++)
    {
        vetDir[j].setCor(v[meio + 1 + j].getCor());
        vetDir[j].setNum(v[meio + 1 + j].getNum());
    }

    int indexEsq = 0; 
    int indexDir = 0; 
    int indexMerged = esq;

    while (indexEsq < tamVetAuxiliar1 && indexDir < tamVetAuxiliar2)
    {
        // Verificar se tem que ser menor ou iggual
        if(comparaMenor(&vetEsq[indexEsq], &vetDir[indexDir])) {
            v[indexMerged].setCor(vetEsq[indexEsq].getCor());
            v[indexMerged].setNum(vetEsq[indexEsq].getNum());
            indexEsq++;
        } else {
            v[indexMerged].setCor(vetDir[indexDir].getCor());
            v[indexMerged].setNum(vetDir[indexDir].getNum());
            indexDir++;
        }
        indexMerged++;
    }
    
     while (indexEsq < tamVetAuxiliar1) {
        v[indexMerged].setCor(vetEsq[indexEsq].getCor());
        v[indexMerged].setNum(vetEsq[indexEsq].getNum());
        indexEsq++;
        indexMerged++;
     }

     while (indexDir < tamVetAuxiliar2) {
        v[indexMerged].setCor(vetDir[indexDir].getCor());
        v[indexMerged].setNum(vetDir[indexDir].getNum());
        indexDir++;
        indexMerged++;
     }    
    

};

void mergeSort(Vertice *v, int comeco, int fim) {
    
    if(comeco >= fim) return;

    int meio = comeco + (fim - comeco) / 2;

    mergeSort(v, comeco, meio);

    mergeSort(v, meio + 1, fim);

    merge(v, comeco, meio, fim);
};

void heapSort(Vertice *v, int n) {

    Heap heap(n);

    for (int i = 0; i < n; i++)
    {
        heap.Inserir(v[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        Vertice tmp = heap.Remover();
        v[i].setCor(tmp.getCor());
        v[i].setNum(tmp.getNum());
    }

};

// O Vetor Naturalmente vem ordernado por NUM, então apenas preciso ordenar de trás para frente por cor
void countingSortByColor(Vertice *v, int n, int maxCor) {
    int countCor[maxCor + 1] = {0};
    Vertice *output = new Vertice[n];

    // Contagem das cores
    for (int i = 0; i < n; i++) {
        countCor[v[i].getCor()]++;
    }

    // Atualização das contagens para incluir a soma acumulada
    for (int i = 1; i <= maxCor; i++) {
        countCor[i] += countCor[i - 1];
    }

    // Classificação por cor (de trás para frente para manter a ordem estável)
    for (int i = n - 1; i >= 0; i--) {
        output[countCor[v[i].getCor()] - 1] = v[i];
        countCor[v[i].getCor()]--;
    }

    // Copia o vetor ordenado de volta para o vetor original
    for (int i = 0; i < n; i++) {
        v[i] = output[i];
    }

    delete[] output;
}











