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
void swap(element_t* n1, element_t* n2);

int main(void){
   loginfo_t loginfo;
   int qtd;
   array_t array1 = {1,2,4,6,7,8,15,22,23};
   array_t array2 = {1,2,3,4,5,6,7,8,25,27,35,44};
   array_t array3, array4;
   array_t array5 = {1,9,8,72,64,1,1,32,1};
   array_t array6 = {1,1,1,1,8,9,32,64,72};



  vector<array_t> arrays = { array1, array2, array3};
  two_way_merge(arrays, array4, loginfo);
  for(auto e:array4) cout << e << " ";  
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
