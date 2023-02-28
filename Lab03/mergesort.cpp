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

/*
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

   for(auto e:array5) cout << e << " ";  
      cout << endl;
   mergesort(array5, loginfo);
   for(auto e:array5) cout << e << " ";  
      cout << endl;



0
*/
   for(auto e:array5) cout << e << " ";  
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
   // TODO: atualizar loginfo

   int n = arrays.size(); 

   //arrays vazio:
   if (n == 0) {
      return; 
   }     

   // começo colocando o primeiro array em auxiliar
   std::vector<int> auxiliar = arrays[0];
   std::vector<int> combinado;
 
   for (int i = 1; i < n; i++ ) {   
      //agora intercala ordenando      
      merge(auxiliar, arrays[i], combinado, loginfo);

      //substitui auxiliar pelo resultado
      auxiliar = combinado; 
      combinado.clear();  
   }

   //coloco o resultado em array_final
   array_final = auxiliar; 
}

void mergesort (array_t& array, loginfo_t& loginfo) {
   // TODO: atualizar loginfo
 
   int n = array.size();
    
   if (n < 2) {
        return;
    }
   int mid = n / 2;
   vector<int> left(array.begin(), array.begin() + mid);
   vector<int> right(array.begin() + mid, array.end());
   mergesort(left, loginfo);
   mergesort(right, loginfo);
   merge(left, right, array, loginfo);
}

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


