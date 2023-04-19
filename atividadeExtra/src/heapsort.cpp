#include "../include/bib.h"

using namespace std;
void heapify(array_t arr, int n, int i, loginfo_t &loginfo){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    get<1>(loginfo)++;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    get<1>(loginfo)++;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i){
        swap(arr[i], arr[largest]);
        get<0>(loginfo)++;

        heapify(arr, n, largest, loginfo);
    }
}

void heapSort(array_t arr, int n, loginfo_t &loginfo) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, loginfo);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        get<0>(loginfo)++;
        heapify(arr, i, 0, loginfo);
    }
}