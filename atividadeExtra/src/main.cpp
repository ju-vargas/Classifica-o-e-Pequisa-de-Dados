// Bibliotecas
#include "../include/bib.h"
using namespace std;

 


int main(){  

    //CRIAÇÃO DOS ARRAYS A SEREM ORDENADOS *************************************************************************************

    //10.000.000 -------------
    //declaro o tamanho 
    array_size_t fullArraySize;
    fullArraySize = 10000000; 

    //declaro os arrays que serao criados 
    array_t fullRandom = new int[fullArraySize]; 
    array_t fullOrder = new int[fullArraySize]; 
    array_t fullInverse = new int[fullArraySize]; 

    //RANDOM
    //preencho o array random
    readInt(fullRandom, fullArraySize); 
    
    //ORDENADOS
    //preencho o array de ordenados 
    loginfo_t loginfoDFullOrder;                                         
    readInt(fullOrder, fullArraySize); 

    //ordeno esse array de ordenados
    randomquicksort(fullOrder, 0, fullArraySize-1, loginfoDFullOrder);

    //INVERTIDOS
    //preencho o array de invertidos
    for(auto i = fullArraySize; i>0; i--) {
         fullInverse[fullArraySize - i]  = fullOrder[i];
    }

    calcForSize(fullRandom,fullOrder,fullInverse,10000000);


    //1.000
    calcForSize(fullRandom,fullOrder,fullInverse,1000);
    //10.000
    calcForSize(fullRandom,fullOrder,fullInverse,10000);
    //100.000
    calcForSize(fullRandom,fullOrder,fullInverse,100000);
    //1.000.000
    calcForSize(fullRandom,fullOrder,fullInverse,1000000);
    //10.000.000
    calcForSize(fullRandom,fullOrder,fullInverse,10000000);



    return 0; 
}



    //testes
    // for(auto i = 0; i<120; i++) 
    //     cout << fullRandomVector[i] << endl; 
    //     cout << "o" << fullRandomVector[8569000];
    // return 0; 

    //fullRandomVector = arrayToVector(fullRandom, fullArraySize); 
    //mergesort(fullRandomVector, loginfo); 

