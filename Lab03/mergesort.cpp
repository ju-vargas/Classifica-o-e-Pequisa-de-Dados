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
typedef tuple<int, int, std::chrono::duration<double>> loginfo_t;                                      // armazena informações de desempenho <trocas, comparações, tempo em ms>

void merge(const array_t&, const array_t&, array_t&, loginfo_t&);
void mergesort(array_t&, loginfo_t&);
void swap(element_t* n1, element_t* n2);


int main(void){
    loginfo_t loginfo;
    int qtd;
    array_t array1 = {1,2,4,6,7,8,15,22,23};
    array_t array2 = {1,2,3,4,5,6,7,8,25,27,35,44};
    array_t array3, array4;
    array_t array5 = {1,9,8,72,64,1,1,32,1};
    array_t array6 = {1,1,1,1,8,9,32,64,72};

    array_t array; 

    auto start = std::chrono::steady_clock::now();
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds;
    

   cout << "Merge Sort: " << endl << endl; 
   cout << "CRESCENTE" << endl; 

   //array crescente de 100 elementos
   cout << "1000 elementos" << endl; 
   for(auto i = 0; i<1000; i++){
      array.push_back(i); 
   }                 

   
    start = std::chrono::steady_clock::now();
    mergesort(array, loginfo);
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(loginfo) = elapsed_seconds; 
   
    cout << "trocas = " << get<0>(loginfo) << "; "; 
    cout << "comparacoes = " << get<1>(loginfo) << "; "; 
    cout << "tempo = " << get<2>(loginfo).count() << "ms; " << endl; 

   get<0>(loginfo) = 0; 
   get<1>(loginfo) = 0; 
   

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
      comparacoes++;      
      trocas++;
    }
    
   if(j<qtd_a2 && i>=qtd_a1)                                                   // array 1 terminou
      for(auto e=j;e<qtd_a2;e++) {
         array_final.push_back(array2[e]);
         trocas++;
      }
    
   if(i<qtd_a1 && j>=qtd_a2)                                                   // array 2 terminou
      for(auto e=i;e<qtd_a1;e++) {
         array_final.push_back(array1[e]);
         trocas++;
      }

   get<0>(loginfo)=trocas;
   get<1>(loginfo)=comparacoes;
    // TODO: atualizar loginfo
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




