#include "../include/bib.h"

using namespace std;

loginfo_t shellsort(array_t array, array_size_t array_size){
    double trocas = 0, comparacoes = 0;
    int h = 1; 
    int k = 1; 
    int chave, i; 

    loginfo_t loginfoAux; 

    //gap h baseado no algoritmo de Knuth O (n^3/2)
    while (h < array_size) {
        h =  (pow(3,k) - 1)/2; 
        k++; 
    }
    while (h>0) {
        for (int j = h; j<array_size; j++) {
            chave = array[j]; 
            i = (j-h);
            comparacoes++;                                                  //comparo array[i] com chave abaixo
            while (i>=0 && array[i]>chave) {
                array[i+h] = array[i];
                trocas+=2;                                                  //pois ja conto a troca de [i+h] com a chave. nao considero troca se é igual
                i = i-h;
            } 
            array[i+h] = chave;
        }
        /* para ver visualmente como está ordenando
        cout << "\n"; 
        for (int u=0; u<array_size; u++) {
            if(u%h == 0)
                cout << "|"<< array[u] <<"|";
            else 
                cout << " "<< array[u] <<" ";
        }
        cout << "\n"; 
        */
        h = (h+1)/3;
    }

    get<0>(loginfoAux) = trocas; 
    get<1>(loginfoAux) = comparacoes; 

    return loginfoAux;                                     // retorna quantidade de operações
}