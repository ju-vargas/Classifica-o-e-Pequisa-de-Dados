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
   array_t array1 = {1,2,4,6,7,8,15,22,23};
   array_t array2 = {1,2,3,4,5,6,7,8,25,27,35,44};
   array_t array3, array4;
   array_t array5 = {1,9,8,72,64,1,1,32,1};
   array_t array6 = {1,1,1,1,8,9,32,64,72};

   vector<array_t> arrays = { array1, array2, array3, array6};
   multi_way_merge(arrays, array4, loginfo);
   for(auto e:array4) cout << e << " ";  
   cout << endl;

  // TODO: mostrar log de operações

  return 0;
}

// ======================================================================================================================================
// Algoritmos de intercalação


// Recebe uma lista de arrays e intercala-os usando estrutura similar a heap-min
// fiz diferente!!
void multi_way_merge(const vector<array_t> arrays, array_t& array_final, loginfo_t& loginfo){           
   // TODO: implementar    
   // TODO: atualizar loginfo

  
  int n = arrays.size();
    vector<int> idx(n, 0); // vetor de índices 

    while (true) {
        int min_element = INT_MAX;
        int min_array_idx = -1;

        // encontra o menor elemento entre os elementos atuais de cada array
        for (int i = 0; i < n; i++) {
            // vejo se já nao acabou o array, e se eh menor q o min elemento. se eh, atualizo
            // o min_array_idx serve pra saber se ja acabou, pq dai nao entra aqui
            if (idx[i] < arrays[i].size() && arrays[i][idx[i]] < min_element) { 
                min_element = arrays[i][idx[i]];
                min_array_idx = i;
            }
        }

        if (min_array_idx == -1) {
            break; // todos os elementos dos arrays já foram processados
        }

        // adiciona o menor elemento encontrado ao resultado final
        array_final.push_back(min_element);

        // atualiza o índice correspondente ao array do elemento adicionado
        // ou seja, sobe
        idx[min_array_idx]++;
    }
}


