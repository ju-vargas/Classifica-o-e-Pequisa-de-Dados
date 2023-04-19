#include "../include/bib.h"

using namespace std;


// BUBBLESORT  -- loginfo serve para guardar número de trocar e comparações
void bubblesort(array_t array, array_size_t array_size, loginfo_t& loginfo){
    double trocas = 0;
    double comparacoes = 0;
    int pos_troca = 0;
    bool troca = true;
    int qtd_elementos = array_size-1;
    get<0>(loginfo) = 0; 
    get<1>(loginfo) = 0; 

    while(troca){
        troca = false;
        for(auto i=0; i<qtd_elementos;i++){ 
            comparacoes = comparacoes + 1;
            if( array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                troca = true;
                pos_troca = i;
                trocas = trocas + 1;
            }
        }
        qtd_elementos = pos_troca;                
    }

    get<0>(loginfo)=trocas;
    get<1>(loginfo)=comparacoes;
}