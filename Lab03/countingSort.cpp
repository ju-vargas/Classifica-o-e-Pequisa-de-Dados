#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include<chrono>

using namespace std;

// Definições e variáveis globais necessárias
typedef int element_t;                                                      // tipo do elemento
typedef vector<element_t> array_t;                                          // tipo do array
typedef tuple<int, int, std::chrono::duration<double>> loginfo_t;           // armazena informações de desempenho <trocas, comparações, tempo em ms>


void countingSort(vector<int>& arr, int maxVal);


int main() {
    loginfo_t loginfo;
    vector<int> arr(100);
    

    auto start = std::chrono::steady_clock::now();
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    cout << "Array original: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    start = std::chrono::steady_clock::now();
    countingSort(arr, 100);
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(loginfo) = elapsed_seconds; 

    cout << "tempo = " << get<2>(loginfo).count() << "ms; " << endl; 

    cout << "Array ordenado: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    vector<int> output(arr.size(), 0);

    // conta ocorrencia de cada elemento
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // calcula soma
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    // Coloca no output de forma ordenada
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia ordenado pro original
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

