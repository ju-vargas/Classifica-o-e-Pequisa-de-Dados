#include "../include/bib.h"

using namespace std;


void merge(const vector_array_t& array1, const vector_array_t& array2, vector_array_t& array_final, loginfo_t& loginfo){
   int i = 0, j = 0;
   double trocas = 0, comparacoes = 0;
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

   //= ou +=?
   //get<0>(loginfo)+=trocas;
   get<1>(loginfo)+=comparacoes;
}

void mergesort (vector_array_t& array, loginfo_t& loginfo) {
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



  