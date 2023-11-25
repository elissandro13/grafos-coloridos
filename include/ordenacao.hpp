#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include "vertice.hpp"

void swap(Vertice * a, Vertice * b);

bool comparaMenor(Vertice *a, Vertice *b);

bool comparaMaior(Vertice *a, Vertice *b);

void bubbleSort(Vertice *v, int n);

void selectionSort(Vertice *v, int n);

void insertionSort(Vertice *v, int n);

int partition(Vertice *v, int menor, int maior);

void quickSort(Vertice *v, int menor,int maior);

void merge(Vertice *v, int esq, int meio, int dir);

void mergeSort(Vertice *v, int comeco, int fim);

void heapSort(Vertice *v, int n);

void countingSortByColor(Vertice *v, int n, int maxCor);





#endif
