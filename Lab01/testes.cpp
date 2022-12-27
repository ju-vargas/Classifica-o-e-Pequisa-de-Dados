#include<iostream>
#include<tuple>
#include<random>
#include<bits/stdc++.h>
#include <string>


//TODO: executar várias vezes os algoritmos, com tamanhos diferentes (e.g., 100, 1000 e 10000)


using namespace std;

typedef int array_size_t;                                                       // Tipo para especificar tamanho do array
typedef int* array_t;                                                           // Tipo para especificar formato do array
typedef std::tuple<int, int> loginfo_t;                                         // armazena contagem de comparações e trocas  
typedef std::tuple<std::string, int, int> loginfo_teste;
typedef std::mt19937 MyRNG;                                                     // Gerador de números aleatórios do tipo Mersenne Twister Random Generator 

MyRNG rng;                                                                      // gerador de números aleatórios
uint32_t seed_val;                                                              // semente de geração de números

loginfo_t insertion_sort(array_t, array_size_t);
loginfo_t insertion_sortBB(array_t, array_size_t);
loginfo_t shellsort(array_t, array_size_t);
std::tuple<int, int, int> busca_binaria(array_t, int, int, int);                // retorna uma tupla contendo <posicao, qtd de trocas, qtd de comparações>

int main(void){    
    // cout << __cplusplus << endl;                                             // verifica versão do compilador
    rng.seed(seed_val);                                                         // inicializa semente de geração de números aleatórios    
    uniform_int_distribution<> distrib(0, INT_MAX);                             // cria gerador com distribuição uniforme entre 0 e MAX_INT
    loginfo_t loginfo;                                                          // armazena contadores de comparações e trocas (ver typedef acima)

    int MAX = 50; 
    int* array = new int[MAX];                                                  // array dinâmico que armazena os números
    loginfo_teste* array_teste = new loginfo_teste[27];


    MAX = 10;
    int j = 0; 
        for (int u = 0; u < 3; u++) { 
            int* array = new int[MAX]; 
            //aleatorio
            for(auto i=0;i<MAX;i++) array[i] = distrib(rng)%51;
            get<0>(array_teste[j]) = "ALEATORIO - Insertion"; 
            get<1>(array_teste[j]) = get<0>(insertion_sort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sort(array, MAX));

            for(auto i=0;i<MAX;i++) array[i] = distrib(rng)%51;
            get<0>(array_teste[j]) = "ALEATORIO - Insertion BB"; 
            get<1>(array_teste[j]) = get<0>(insertion_sortBB(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sortBB(array, MAX));

            for(auto i=0;i<MAX;i++) array[i] = distrib(rng)%51;
            get<0>(array_teste[j]) = "ALEATORIO - ShellSort"; 
            get<1>(array_teste[j]) = get<0>(shellsort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(shellsort(array, MAX));

            //crescente
            for(auto i=0;i<MAX;i++) array[i] = i;
            get<0>(array_teste[j]) = "CRESCENTE - Insertion"; 
            get<1>(array_teste[j]) = get<0>(insertion_sort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sort(array, MAX));

            for(auto i=0;i<MAX;i++) array[i] = i;
            get<0>(array_teste[j]) = "CRESCENTE - Insertion BB"; 
            get<1>(array_teste[j]) = get<0>(insertion_sortBB(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sortBB(array, MAX));
            
            for(auto i=0;i<MAX;i++) array[i] = i;
            get<0>(array_teste[j]) = "CRESCENTE - ShellSort"; 
            get<1>(array_teste[j]) = get<0>(shellsort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(shellsort(array, MAX));
            
            //decrescente
            for(auto i=0;i<MAX;i++) array[i] = MAX-i;
            get<0>(array_teste[j]) = "DECRESCENTE - Insertion"; 
            get<1>(array_teste[j]) = get<0>(insertion_sort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sort(array, MAX));

            for(auto i=0;i<MAX;i++) array[i] = MAX-i;
            get<0>(array_teste[j]) = "DECRESCENTE - Insertion BB"; 
            get<1>(array_teste[j]) = get<0>(insertion_sortBB(array, MAX));
            get<2>(array_teste[j++]) = get<1>(insertion_sortBB(array, MAX));

            for(auto i=0;i<MAX;i++) array[i] = MAX-i;
            get<0>(array_teste[j]) = "DECRESCENTE - ShellSort"; 
            get<1>(array_teste[j]) = get<0>(shellsort(array, MAX));
            get<2>(array_teste[j++]) = get<1>(shellsort(array, MAX));

            delete[] array;
            MAX = MAX * 10; 
        }

    cout << endl ;
    int tamanho = 10; 

    for (int j = 0; j < 3; j++) {      
        cout << "\n\nTamanho: "<<tamanho << "\n"; 

        for (int i = 0; i<9; i++){
            cout << get<0>(array_teste[i + 9*j]) << "\n";
            cout << "Quantidade de trocas: " << get<1>(array_teste[i + 9*j]) << "\n";
            cout << "Quantidade de comparações: " << get<2>(array_teste[i + 9*j]) << "\n\n";
        }
        tamanho = tamanho * 10; 
    }


    

    // TODO: mostrar informações de execução de todos os algoritmos
    delete[] array_teste;
    return 0;
}





// Função de Inserção Direta com Busca Linear
loginfo_t insertion_sort(array_t array, array_size_t array_size){
    int trocas = 0, comparacoes = 0;
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
    return make_tuple(trocas, comparacoes);                                     // retorna quantidade de operações
}
/* INSERTION SORT COM BUSCA BINÁRIA
> O primeiro elemento do array está ordenado, e o resto não.
> Um por um, os outros elementos são colocados na parte ordenada. 
> Seu lugar na parte ordenada é encontrado com busca binaria 
*/

loginfo_t insertion_sortBB(array_t array, array_size_t array_size){    
   int trocas = 0, comparacoes = 0;
   std::tuple<int, int, int> info;
   int i, local, j, k, elemento;

   for(i = 1; i < array_size; i++) {
        j = i - 1;                                   // j é esse primeiro elemento já ordenado. depois, é o fim dos elementos ordenados. 

        elemento = array[i];                  
        info = busca_binaria(array, elemento,0,j);   // pego o elemento i, e descubro onde ele esta no array ordenado (?). percorro array de 0 a j
                                                   // ele nao vai estar em nenhum lugar! mas vou saber onde inserir

        local = get<0>(info);                        //pego o valor retornado pela tupla. no primeiro elemento, vai ser 0, mas deveria ser 1??
        trocas += get<1>(info);
        comparacoes += get<2>(info)+1;

        while (j >= local) {                         // aqui, eu faço as trocas necessárias pra colocar o elemento onde deve estar no array
            trocas++;                                 //"abre espaço", empurro pro final
            array[j+1] = array[j];
            j--;
        }
        if(j+1 != i){                                 //troca oficial
            array[j+1] = elemento;
            trocas++;
        }
   }
    return make_tuple(trocas, comparacoes);       // retorna quantidade de operações
}

// *****************************************************
//  TODO: Implementação dos seus algoritmos (a seguir)

// Faz busca binária do 'elemento' no 'array', entre os índices 'inicio' e 'fim'
// retorna posição do elemento, quantidade de trocas e quantidade de comparações

std::tuple<int, int, int> busca_binaria(array_t array, int elemento, int inicio, int fim){
    int comparacoes = 0,                     
    trocas = 0,
    meio = ((fim - inicio) / 2)+ inicio;

    //esse jogo de meio-1, meio+1 e inicio>1, possibilita q o primeiro tenha meio 1 
    //mas, tirar os extremos é o modo de fazer busca binaria
    //o ponto é que assim, se fosse inicio == fim, daria erro na verificação, pq antes disso seria menor (?)

    if (inicio>fim) {                                               //nao foi achado, e acabou a procura.
        comparacoes++; 
        return  make_tuple(meio, trocas, comparacoes); 
    }                      
    if (array[meio] > elemento)  {                                  //se o meio é maior, fim agora é meio menos 1, inicio continua igual
        comparacoes = comparacoes+2; 
        return busca_binaria(array, elemento, inicio, meio-1);
    } 
    if (array[meio] == elemento) {                                  //foi achado (será colocado no lugar onde foi achado, e move esse)
        comparacoes = comparacoes+3; 
        return  make_tuple(meio, trocas, comparacoes); 
    }        
    return busca_binaria(array, elemento, meio+1, fim);             //nao sendo, ele cai aqui. logo, o meio é menor q o elemento. 
}

loginfo_t shellsort(array_t array, array_size_t array_size){
    int trocas = 0, comparacoes = 0;
    int h = 1; 
    int k = 1; 
    int chave, i; 

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
                trocas++;                                                  
                i = i-h;
            } 
            array[i+h] = chave;
            trocas++; 
        }
      
        h = (h+1)/3;
    }
    return make_tuple(trocas, comparacoes);                                     // retorna quantidade de operações
}