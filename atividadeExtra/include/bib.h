#ifndef BIB_H
#define BIB_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
#include <chrono>
#include <cmath> 
#include <bits/stdc++.h>
#include <algorithm>


const int RUN = 32;

using namespace std; 

typedef int array_size_t;                          // Tipo para especificar tamanho do array
typedef int* array_t;                              // Tipo para especificar formato do array
typedef std::tuple<double, double, std::chrono::duration<double>,std::string> loginfo_t;            // armazena contagem de <trocas , comparacoes>

typedef int element_t;                             // tipo do elemento
typedef vector<element_t> vector_array_t;          // tipo do array


//funcoes
int readInt(array_t array, array_size_t size);
void swap(int *n1, int *n2); 
vector_array_t arrayToVector(int *array, int tamanho); 
int writeTxt (loginfo_t loginfo, int tam);
int iniLoginfo (loginfo_t& loginfo);
int nameLoginfo (loginfo_t& loginfo, string label); 
int copyArray(array_t originArr, array_t copyArr, int tam); 

//funcao geral para calculo de cada tamanho
void calcForSize(array_t fullRandom, array_t fullOrder, array_t fullInverse, array_size_t size);

//insertion sort
loginfo_t insertion_sort(array_t array, array_size_t array_size);


//insertion sort binary search
loginfo_t insertion_sortBB(array_t array, array_size_t array_size);
std::tuple<int, int, int> busca_binaria(array_t array, int elemento, int inicio, int fim);

//shell sort
loginfo_t shellsort(array_t array, array_size_t array_size); 

//bubble sort
void bubblesort(array_t array, array_size_t array_size, loginfo_t& loginfo); 

//quick sort randomizado
void randomquicksort(array_t array, int i, int f, loginfo_t& loginfo);
int particiona(array_t array, int esq, int dir, loginfo_t& loginfo); 

//selection sort
void selectionsort(vector_array_t& array, loginfo_t& loginfo); 

//heap sort
void heapify(array_t arr, int n, int i, loginfo_t &loginfo);
void heapSort(array_t arr, int n, loginfo_t &loginfo); 


//tim sort
void insertionSortTim(array_t arr, int left, int right, loginfo_t& loginfo);
void mergeTim(array_t arr, int l, int m, int r, loginfo_t& loginfo);
void timSort(array_t arr, int n, loginfo_t& loginfo);

//merge sort
void merge(const vector_array_t&, const vector_array_t&, vector_array_t&, loginfo_t&);
void mergesort(vector_array_t&, loginfo_t&);

#endif // BIB_H
