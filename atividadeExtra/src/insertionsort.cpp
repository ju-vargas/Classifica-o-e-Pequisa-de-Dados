#include "../include/bib.h"

using namespace std;


// Função de Inserção Direta com Busca Linear
loginfo_t insertion_sort(array_t array, array_size_t array_size){

    loginfo_t infos; 

    double trocas = 0, comparacoes = 0;
    for(int i=1;i<array_size;i++){                                              // do segundo ao último
        auto chave = array[i];                                                  // chave a inserir no subarray ordenado
        auto j = i-1;                                                           // último elemento do subarray ordenado         
        comparacoes = comparacoes + 1;
        while(j >= 0 && array[j] > chave){                                      // busca linear da direita para a esquerda no subarray ordenado   
            comparacoes = comparacoes + 1;
            array[j+1] = array[j];
            j = j - 1;
            trocas = trocas + 1;
        }
        if(j+1 != i){ 
           array[j+1] = chave;
           trocas = trocas + 1;
       }
    }

    get<0>(infos) = trocas;
    get<1>(infos) = comparacoes; 
    return infos;                                     // retorna quantidade de operações
}
