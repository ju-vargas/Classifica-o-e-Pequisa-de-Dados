#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
#include<map>

using namespace std;

// Definições e variáveis globais necessárias
typedef int element_t;                                  // tipo do elemento
typedef vector<element_t> array_t;                      // tipo do array
typedef tuple<int, int, double> loginfo_t;              // armazena informações de desempenho <trocas, comparações, tempo em ms>

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
    array_t array1 = {1,2,3,4,5,6,7,8};                   // array a ser ordenado

    buildheap(array1, loginfo);
  
    for(auto e:array1)
        cout << e << " ";                                 // for pra printar elementos do array  
    cout << endl;

    heapsort(array1, loginfo);

    for(auto e:array1)
        cout << e << " ";                            
    cout << endl;

  return 0;
}

// =============================================================================================================================
// Algoritmos de ordenação por Seleção


// SELEÇÃO DIRETA 
void selectionsort(array_t& array, loginfo_t& loginfo){
    int trocas = 0;
    int comparacoes = 0;
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