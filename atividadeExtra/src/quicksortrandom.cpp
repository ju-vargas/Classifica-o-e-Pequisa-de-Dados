#include "../include/bib.h"

using namespace std;

// RANDOM QUICKSORT
void randomquicksort(array_t array, int i, int f, loginfo_t& loginfo){
    int p;                                              //p é o pivo?
     
	if(f>i){
		p = particiona(array, i, f, loginfo);         //(array, inicio do array, final do array, info q guarda trocas e comparações)
		randomquicksort(array, i, p-1, loginfo);            //lado esquerdo do array, p é o meio
		randomquicksort(array, p+1, f, loginfo);            //lado direito do array, p é o meio 
	}                                               //faço pras novas metades
}

int particiona(array_t array, int esq, int dir, loginfo_t& loginfo){
    int i=esq+1, j=dir;
    int pivo; 

    srand(time(NULL));
    pivo = esq + rand() % (dir - esq);

    swap(&array[pivo], &array[esq]);
    pivo = esq; 

    while(j>i){
        while(array[i]<array[pivo] && i<dir) {
            i++;
            get<1>(loginfo)++;
        }
        while(array[j]>=array[pivo] && j>esq){             
            j--;
            get<1>(loginfo)++;
        }

        if(i<j && array[i]>array[j]){
           swap(&array[i], &array[j]);
           get<0>(loginfo)++;
           get<1>(loginfo)++;
        }
    }
    //get<1>(loginfo)++;
    if(array[j]<array[pivo]){
	   	swap(&array[pivo], &array[j]);
     	get<0>(loginfo)++;
      get<1>(loginfo)++;
    }
    return j;
}

