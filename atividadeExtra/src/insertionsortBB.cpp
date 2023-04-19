#include "../include/bib.h"

using namespace std;



loginfo_t insertion_sortBB(array_t array, array_size_t array_size){    
   double trocas = 0, comparacoes = 0;
   std::tuple<double, double, int> info;
   int i, local, j, k, elemento;
   loginfo_t infos; 


   for(i = 1; i < array_size; i++) {
        j = i - 1;                                 //j é esse primeiro elemento já ordenado. depois, é o fim dos elementos ordenados.       
        elemento = array[i];                  
        info = busca_binaria(array, elemento,0,j); //pego o elemento i, e descubro onde ele esta no array ordenado (?). percorro array de 0 a j
                                                   //ele nao vai estar em nenhum lugar! mas vou saber onde inserir
        local = get<0>(info);                      //pego o valor retornado pela tupla. no primeiro elemento, vai ser 0, mas deveria ser 1??
        trocas += get<1>(info);
        comparacoes += get<2>(info)+1;
        //ver se to contando certo
        //comparacoes = get<2>(info)+1;

        while (j >= local) {                      //aqui, eu faço as trocas necessárias pra colocar o elemento onde deve estar no array
            trocas++;                             //"abre espaço", empurro pro final
            array[j+1] = array[j];
            j--;
        }
        if(j+1 != i){                             //troca oficial
            array[j+1] = elemento;
            trocas++;
        }
   }
    get<0>(infos) = trocas;
    get<1>(infos) = comparacoes; 
    return infos; 
}

std::tuple<int, int, int> busca_binaria(array_t array, int elemento, int inicio, int fim){
    double comparacoes = 0,                     
    trocas = 0;

    int meio = ((fim - inicio) / 2)+ inicio;

    //esse jogo de meio-1, meio+1 e inicio>1, possibilita q o primeiro tenha meio 1 
    //mas, tirar os extremos é o modo de fazer busca binaria
    //o ponto é que assim, se fosse inicio == fim, daria erro na verificação, pq antes disso seria menor (?)

    if (inicio>fim) {                            //nao foi achado, e acabou a procura.
        comparacoes++; 
        return  make_tuple(meio, trocas, comparacoes); 
    }                      
    if (array[meio] > elemento)  {              //se o meio é maior, fim agora é meio menos 1, inicio continua igual
        comparacoes = comparacoes++; 
        return busca_binaria(array, elemento, inicio, meio-1);
    } 
    if (array[meio] == elemento) {              //foi achado (será colocado no lugar onde foi achado, e move esse)
        comparacoes = comparacoes++; 
        return  make_tuple(meio, trocas, comparacoes); 
    }        
    return busca_binaria(array, elemento, meio+1, fim);    //nao sendo, ele cai aqui. logo, o meio é menor q o elemento. 
}