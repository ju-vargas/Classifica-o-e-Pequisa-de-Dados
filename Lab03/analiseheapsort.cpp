#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
#include<map>
#include<chrono>

using namespace std;

// Definições e variáveis globais necessárias
typedef int element_t;                                  // tipo do elemento
typedef vector<element_t> array_t;                      // tipo do array
typedef tuple<int, int, std::chrono::duration<double>> loginfo_t;              // armazena informações de desempenho <trocas, comparações, tempo em ms>

void selectionsort(array_t&, loginfo_t&);
void heapsort(array_t&, loginfo_t&);
void buildheap(array_t&, loginfo_t&);
int filho_e(const array_t&, element_t);
int filho_d(const array_t&, element_t);
int pai(const array_t&, element_t);
void heapify(array_t&, element_t, int, loginfo_t&);
int heap_max(const array_t&, loginfo_t&);
int extract_max(array_t&, loginfo_t&);
void heap_insert(array_t&, element_t, loginfo_t&);
void swap(element_t* n1, element_t* n2);

int main(void){

    loginfo_t loginfo;
    int qtd;

    

    array_t array;                  
    array_t array1;                  

//<trocas, comparações, tempo em ms>
//---------------------------------------------------------------------------------------------------------------------
    
    auto start = std::chrono::steady_clock::now();
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds;
    
    cout << "CRESCENTE" << endl; 

    //array crescente de 100 elementos
    cout << "100 elementos" << endl; 
    for(auto i = 0; i<100; i++){
        array.push_back(i); 
    }

    start = std::chrono::steady_clock::now();
    
    buildheap(array, loginfo);
    heapsort(array, loginfo);
    
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(loginfo) = elapsed_seconds; 

    cout << "trocas = " << get<0>(loginfo) << "; "; 
    cout << "comparacoes = " << get<1>(loginfo) << "; "; 
    cout << "tempo = " << get<2>(loginfo).count() << "ms; " << endl; 
    
    return 0;
}


// =============================================================================================================================
// Algoritmos de ordenação por Seleção

// HEAPSORT 
void heapsort(array_t& array, loginfo_t& loginfo){
    int trocas = 0;
    int comparacoes = 0;
    int heap_size = array.size();               // heap size retorna o  numero de elementos  do heap 
    int qtd_elementos = heap_size-1;            // qnt_elementos é o    numero de elementos  menos 1

    buildheap(array, loginfo);                  // deixa em formato de heap


    for(auto i = qtd_elementos; i>0; i--){      // vindo do último elemento, eu subtraio e percorro enquanto i nao é 0   
        trocas++;                               // se sao 3 elementos, qnt = 2, itero 2 vezes, NUNCA chego no elemento array[0] primeiro
       
        swap(array[i], array[0]);               // troco o ultimo elemento do array com o primeiro do array[0]  (o primeiro é p ser o maior)
        heap_size--;                            // diminuo o tamanho do array (era 3, 2)
        heapify(array, 0, heap_size, loginfo);  // mando o array, o tamanho organizo. ele nao pega o ultimo elemento, q eu coloquei fora
                                                // ele pega o elemento [0] q eu tinha trocado e organiza o heap p esse ter o maior de novo      

    }
    get<0>(loginfo)=trocas;
    get<1>(loginfo)=comparacoes;
}

// HEAPSORT - Funcoes auxiliares
void buildheap(array_t& array, loginfo_t& loginfo){
    int ultimo_pai = (array.size()/2)-1;
    for(auto i=ultimo_pai; i>=0; i--)
        heapify(array, i, array.size(), loginfo);
}
  
int filho_e(const array_t& array, element_t elemento){
    return elemento*2+1;
}
 
int filho_d(const array_t& array, element_t elemento){
    return elemento*2+2;
}
 
int pai(const array_t& array, element_t elemento){
    return (elemento/2);
}
 
// heapify: verifica se o elemento na posição passada é um heap e se não for transforma-o em um
// parâmetros: array, índice do elemento a heapificar, tamanho do heap, dicionário de logs
// ou seja, coloca no lugar
void heapify(array_t& array, element_t elemento, int heap_size, loginfo_t& loginfo){
    // índice do elemento a ser reorganizado: recebe o 0 para o heapsort (pois é o que to mudando sempre)
    //elemente_t eh do tipo int

    element_t esq, dir, maior; 

    esq = filho_e(array, elemento);  
    dir = filho_d(array, elemento);
    maior = elemento;                   //se estivesse correto o índice do maior seria o 0

    //aqui descubro qual filho é maior que o pai (ou se nenhum eh)
    if ((esq < heap_size) & (array[esq] > array[maior])) //se esq eh valido e o valor e maior q o pai 
        maior = esq;
    if ((dir < heap_size) & (array[dir] > array[maior]))
        maior = dir; 

    if (maior != elemento) {
        swap(array[elemento], array[maior]);
        heapify(array, maior, heap_size, loginfo); //heapsize nao muda dentro da funcao, posso mandar o mesmo
    }
}


 
//Máximo(S): Retorna o elemento de S com maior valor de chave
int heap_max(array_t& heap, loginfo_t& loginfo){
    return heap[0];
}

int extract_max(array_t& heap, loginfo_t& loginfo){    
    int heap_size = heap.size(); 
    element_t max; 

    if(heap_size < 1)
        cout << "erro: heap underflow!";  
    max = heap[0]; 
    heap[0] = heap[heap_size]; 
    heap_size = heap_size-1;                    // assim ele tirou o 0 trocando com o ultimo 
    heapify (heap, 0, heap_size, loginfo);      // preciso arrumar o que eu troquei  
    return max;                                 // retorno o valor máximo
}

void heap_insert(array_t& heap, element_t elemento, loginfo_t& loginfo){
    int heap_size; 
    heap_size = heap.size() + 1;                // ja coloco o tamanho aumentado
    
    auto i = heap_size;

    while ((i > 0) && heap[pai(heap, i)] < elemento) {
        heap[i] = heap[pai(heap,i)];
        i = pai(heap,i); 
    }
    heap[i] = elemento; 
}

//OUTRAS funcoes auxiliares
//swap
void swap(element_t* n1, element_t* n2){
	int troca = *n1;
	*n1 = *n2;
	*n2 = troca;
}