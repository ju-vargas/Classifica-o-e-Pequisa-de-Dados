#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
#include<map>

using namespace std;

// Definições e variáveis globais necessárias
typedef int element_t;                                                          // tipo do elemento
typedef vector<element_t> array_t;                                              // tipo do array
typedef tuple<int, int, double> loginfo_t;                                      // armazena informações de desempenho <trocas, comparações, tempo em ms>

void merge(const array_t&, const array_t&, array_t&, loginfo_t&);
void two_way_merge(const vector<array_t>, array_t&, loginfo_t&);
void multi_way_merge(const vector<array_t>, array_t&, loginfo_t&);
void mergesort(array_t&, loginfo_t&);
void swap(element_t* n1, element_t* n2);
void merge_aux(array_t&, int, int, int, loginfo_t&);
void mergesort_aux(array_t&, int, int, loginfo_t&);

int main(void){
  loginfo_t loginfo;
  int qtd;
  array_t array1 = {1,2,4,6,7,8,15,22};
  array_t array2 = {1,2,3,4,5,6,7,8,25,27,35,44};
  array_t array3, array4;
  array_t array5 = {10,9,8,7,6,5,4,3,2,1};

  for(auto e:array1) cout << e << " ";  
  cout << endl;

  for(auto e:array2) cout << e << " ";  
  cout << endl;

  merge(array1, array2, array3, loginfo);
  
  for(auto e:array3) cout << e << " ";  
  cout << endl;

  vector<array_t> arrays = { array1, array2, array3};
  two_way_merge(arrays, array4, loginfo);
  for(auto e:array4) cout << e << " ";  
  cout << endl;

  multi_way_merge(arrays, array4, loginfo);
  for(auto e:array4) cout << e << " ";  
  cout << endl;

  mergesort(array5, loginfo);
  for(auto e:array5) cout << e << " ";  
  cout << endl;

  // TODO: mostrar log de operações

  return 0;
}

// ======================================================================================================================================
// Algoritmos de intercalação
void merge(const array_t& array1, const array_t& array2, array_t& array_final, loginfo_t& loginfo){
    int i = 0, j = 0, trocas = 0, comparacoes = 0;
    int qtd_a1 = array1.size();
    int qtd_a2 = array2.size();
    
    bool elementos = true;
    array_final.clear();    
    while(i<qtd_a1 && j<qtd_a2){
       if(array1[i] <= array2[j])
          array_final.push_back(array1[i++]);          
       else
          array_final.push_back(array2[j++]);       
    }
    
    if(j<qtd_a2 && i>=qtd_a1)                                                   // array 1 terminou
       for(auto e=j;e<qtd_a2;e++)
          array_final.push_back(array2[e]);
    
    if(i<qtd_a1 && j>=qtd_a2)                                                   // array 2 terminou
       for(auto e=i;e<qtd_a1;e++)
          array_final.push_back(array1[e]);

    // TODO: atualizar loginfo
}

// Recebe uma lista de arrays e intercala-os 2 a 2
// retorna um array com o resultado da intercalação
void two_way_merge(const vector<array_t> arrays, array_t& array_final, loginfo_t& loginfo){   
  // TODO:
}



void mergesort(array_t& array, int inicio, int final, loginfo_t& loginfo){
    int meio;     

    array_t segmentoUm; 
    array_t segmentoDois; 



    meio = (inicio+final)/2;                        // divide em dois segmentos
    mergesort(array, inicio, meio, loginfo);        // chamada recursiva primeiro segmento
    mergesort(array, meio+1, final, loginfo);       // chamada recursiva segundo segmento

    for (auto i = inicio, i )
    merge(array, inicio, meio, fim);                // intercala duas sequencias ordenadas                

}

// Recebe uma lista de arrays e intercala-os usando estrutura similar a heap-min
void multi_way_merge(const vector<array_t> arrays, array_t& array_final, loginfo_t& loginfo){           
    // TODO: implementar    
}