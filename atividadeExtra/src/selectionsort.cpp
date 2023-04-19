#include "../include/bib.h"

using namespace std;

void selectionsort(vector_array_t& array, loginfo_t& loginfo){
    double trocas = 0;
    double comparacoes = 0;
    element_t menorchave;
    int qtd_elementos = array.size()-1;  

    for(auto i=0; i<qtd_elementos;i++){
        menorchave = i;
        for(auto j=i; j<qtd_elementos+1; j++){                   
            comparacoes = comparacoes + 1;
            if(array[j] < array[menorchave]){ 
                menorchave = j;
            }
        }   
        if(menorchave != i){
            swap(array[i], array[menorchave]);
            trocas = trocas + 1;
        }
    }
    get<0>(loginfo)=trocas;
    get<1>(loginfo)=comparacoes;
} 

  