// Atenção: usa código C++11
// para saber se o seu compilador tem suporte, execute: 
// cout << __cplusplus;
// O resultado deve ser 201103L ou maior.
// o do google collab é C++14 
// A grande maioria dos compiladores atuais suporta nativamente c++11. 
// Outros exigem a configuração de parâmetros de compilação... Verifique a documentação do seu.

#include<iostream>
#include<tuple>
#include<random>
#include<bits/stdc++.h>
#include<chrono>
#include<string.h>

using namespace std;

typedef int array_size_t;                                                       // Tipo para especificar tamanho do array
typedef int* array_t;                                                           // Tipo para especificar formato do array
typedef std::tuple<int, int> loginfo_t;                                         // armazena contagem de <trocas , comparacoes>
typedef std::tuple<std::string, int, int, std::chrono::duration<double>> loginfo_teste;                // armazena <tipo, trocas , comparacoes, tempo>
typedef std::mt19937 MyRNG;                                                     // Gerador de números aleatórios do tipo Mersenne Twister Random Generator 

#define MAX 10 


MyRNG rng;                                                                      // gerador de números aleatórios
uint32_t seed_val;                                                              // semente de geração de números

void bubblesort(array_t, array_size_t, loginfo_t&);
void combsort(array_t, array_size_t, loginfo_t&);
void shakesort(array_t, array_size_t, loginfo_t&);

void quicksort(array_t, int, int, loginfo_t&);
int particiona(array_t array, int i, int f, loginfo_t&);
void swap(int *n1, int *n2);

int main(void){    
    rng.seed(seed_val);                                                         // inicializa semente de geração de números aleatórios    
    uniform_int_distribution<> distrib(0, INT_MAX);                             // cria gerador com distribuição uniforme entre 0 e MAX_INT

    loginfo_t loginfo;                                                          // armazena contadores de comparações e trocas (ver typedef acima)
    loginfo_teste* array_teste = new loginfo_teste[16];                         // armazena informações de teste 
    int* array = new int[MAX];                                                  // array dinâmico que armazena os números

/*

    int MAX = 10; 
    int j = 0; 
    for (int u = 0; u < 4; u++) {
        int* array = new int[MAX];                                                  // array dinâmico que armazena os números

        //aleatorio
        get<0>(loginfo) = 0; 
        get<1>(loginfo) = 0;
        for(auto i=0;i<MAX;i++) array[i] = distrib(rng)%51;                         // gera números em ordem aleatória
        start = std::chrono::steady_clock::now();
        quicksort(array, 0, MAX-1, loginfo); 
        finish = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = finish - start;
        get<0>(array_teste[j]) = "ALEATORIO - Quicksort"; 
        get<1>(array_teste[j]) = get<0>(loginfo);
        get<2>(array_teste[j]) = get<1>(loginfo);
        get<3>(array_teste[j++]) = elapsed_seconds;


        //crescente
        get<0>(loginfo) = 0; 
        get<1>(loginfo) = 0;
        for(auto i=0;i<MAX;i++) array[i] = i;
        start = std::chrono::steady_clock::now();
        quicksort(array, 0, MAX-1, loginfo); 
        finish = std::chrono::steady_clock::now();
        elapsed_seconds = finish - start;
        get<0>(array_teste[j]) = "CRESCENTE - Quicksort"; 
        get<1>(array_teste[j]) = get<0>(loginfo);
        get<2>(array_teste[j]) = get<1>(loginfo);
        get<3>(array_teste[j++]) = elapsed_seconds;



        //decrescente
        get<0>(loginfo) = 0; 
        get<1>(loginfo) = 0;
        for(auto i=0;i<MAX;i++) array[i] = MAX-i; 
        start = std::chrono::steady_clock::now();
        quicksort(array, 0, MAX-1, loginfo); 
        finish = std::chrono::steady_clock::now();
        elapsed_seconds = finish - start;
        get<0>(array_teste[j]) = "DECRESCENTE - QuickSort"; 
        get<1>(array_teste[j]) = get<0>(loginfo);
        get<2>(array_teste[j]) = get<1>(loginfo);
        get<3>(array_teste[j++]) = elapsed_seconds;



        //identico
        get<0>(loginfo) = 0; 
        get<1>(loginfo) = 0;
        for(auto i=0;i<MAX;i++) array[i] = MAX; 
        start = std::chrono::steady_clock::now();
        quicksort(array, 0, MAX-1, loginfo); 
        finish = std::chrono::steady_clock::now();
        elapsed_seconds = finish - start;
        get<0>(array_teste[j]) = "IDENTICO - QuickSort"; 
        get<1>(array_teste[j]) = get<0>(loginfo);
        get<2>(array_teste[j]) = get<1>(loginfo);
        get<3>(array_teste[j++]) = elapsed_seconds;

    

        delete[] array; 
        MAX = MAX*10; 
    }


    cout << endl ;
    int tamanho = 10; 

    for (int x = 0; x < 4; x++) {      
        cout << "\n\nTamanho: "<<tamanho << "\n"; 

        for (int i = 0; i<4; i++){
            cout << get<0>(array_teste[i + 4*x]) << "\n";
            cout << "Quantidade de trocas: " << get<1>(array_teste[i + 4*x]) << "\n";
            cout << "Quantidade de comparações: " << get<2>(array_teste[i + 4*x]) << "\n";
            cout << "Tempo: " << (get<3>(array_teste[i + 4*x])).count() << "s"<< "\n\n";
        }
        tamanho = tamanho * 10; 
    }
*/

    //PARTE INDIVIDUAL/ORIGINAL DO CÓDIGO 

    for(auto i=0;i<MAX;i++) array[i] = distrib(rng)%71;                         // gera números em ordem aleatória
    //for(auto i=0;i<MAX;i++) array[i] = i;                                       // gera números em ordem crescente
    //for(auto i=0;i<MAX;i++) array[i] = MAX-i;                                   // gera números em ordem decrescente
    //for(auto i=0;i<MAX;i++) array[i] = MAX;                                     // gera números iguais



    cout << "Array desordenado: ";
    for(auto i=0;i<MAX;i++) cout << array[i] << " ";


    //PARTE Q FAZ TESTES SEPARADAMENTE 
    auto start = std::chrono::steady_clock::now();
    //bubblesort(array, MAX, loginfo);                                         // passa tamanho do array
    shakesort(array, MAX, loginfo); 
    //shakesort(array, MAX, loginfo); 
    //quicksort(array, 0, MAX-1, loginfo);                                      // passa início e fim do trecho de processamento (MAX-1)
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = finish - start;
    
    //TODO: armazenar essas informações em um matriz, hashtable ou arquivo

    cout << endl << "Array ordenado: ";                               
    for(auto i=0;i<MAX;i++) cout << array[i] << " ";

    cout << endl;
    cout << "Quantidade de trocas: " << get<0>(loginfo) << endl;
    cout << "Quantidade de comparações: " << get<1>(loginfo) << endl;
    cout << "Tempo total: " << elapsed_seconds.count() << "s" << endl;  
    
    delete[] array;
    return 0;


}

// QUICKSORT
void quicksort(array_t array, int i, int f, loginfo_t& loginfo){
    int p;                                              //p é o pivo?
     

    if(f>i){
		  p = particiona(array, i, f, loginfo);         //(array, inicio do array, final do array, info q guarda trocas e comparações)
		  quicksort(array, i, p-1, loginfo);            //lado esquerdo do array, p é o meio
		  quicksort(array, p+1, f, loginfo);            //lado direito do array, p é o meio 
	}                                                   //faço pras novas metades
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

void swap(int *n1, int *n2){
	int troca = *n1;
	*n1 = *n2;
	*n2 = troca;
}

// BUBBLESORT 
void bubblesort(array_t array, array_size_t array_size, loginfo_t& loginfo){
    int trocas = 0;
    int comparacoes = 0;
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

// COMBSORT 
void combsort(array_t array, array_size_t array_size, loginfo_t& loginfo){
    int trocas = 0;
    int comparacoes = 0;
    int pos_troca = 0;

    bool troca = true;
    
    int qtd_elementos = array_size-1;
    float fator = 1.3; 
    int gap = qtd_elementos; 

    get<0>(loginfo) = 0; 
    get<1>(loginfo) = 0; 

    while(gap > 1 || troca){
        gap = gap / fator;

        if (gap < 1){
            gap = 1; 
        }
        troca = false; 

        for(auto i=0; i+gap<array_size;i++){ 
            comparacoes = comparacoes + 1;
            if( array[i] > array[i+gap]){
                swap(array[i], array[i+gap]);
                troca = true;
                trocas = trocas + 1;
            }
        }
    }

    get<0>(loginfo)=trocas;
    get<1>(loginfo)=comparacoes;
}

// SHAKESORT 
void shakesort(array_t array, array_size_t array_size, loginfo_t& loginfo){
    int trocas = 0;
    int comparacoes = 0;

    int qtd_elementos = array_size-1;
    
    int esq = 0; 
    int dir = qtd_elementos; 
    bool troca = true;

    get<0>(loginfo) = 0; 
    get<1>(loginfo) = 0; 

    while(troca && esq<dir){
        troca = false;
        for(auto i=esq; i<dir;i++){ 
            comparacoes = comparacoes + 1;
            if( array[i] > array[i+1]){        
                swap(array[i], array[i+1]);
                troca = true;
                trocas++;
            }
        }
        dir--; 

        for(auto i=dir; i>esq;i--){ 
            comparacoes = comparacoes + 1;
            if( array[i] < array[i-1]){
                swap(array[i], array[i-1]);
                troca = true;
                trocas++;
            }
        }
    esq++; 
    }
    get<0>(loginfo)=trocas;
    get<1>(loginfo)=comparacoes;
}