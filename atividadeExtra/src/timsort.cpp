#include "../include/bib.h"

using namespace std;

// C++ program to perform TimSort.

// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSortTim(array_t arr, int left, int right, loginfo_t& loginfo) {
	double trocas = 0, comparacoes = 0; 
	for (int i = left + 1; i <= right; i++){
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
			trocas++;
			comparacoes++; 
			comparacoes++;
		}
		arr[j+1] = temp;
		trocas++; 
	}
	get<0>(loginfo)+=trocas;
    get<1>(loginfo)+=comparacoes;
}

// Merge function merges the sorted runs
void mergeTim(array_t arr, int l, int m, int r, loginfo_t& loginfo) {
	int trocas = 0, comparacoes = 0; 

	// Original array is broken in two parts
	// left and right array
	int len1 = m - l + 1, len2 = r - m;
	int left[len1], right[len2];
	for (int i = 0; i < len1; i++){
		left[i] = arr[l + i];
		trocas++; 
	}
	for (int i = 0; i < len2; i++){
		right[i] = arr[m + 1 + i];
		trocas++; 
	}

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
			comparacoes++;
			trocas++;
		}
		else{
			arr[k] = right[j];
			j++;
			comparacoes++;
			trocas++;
		}
		k++;
	}

	// Copy remaining elements of left, if any
	while (i < len1){
		arr[k] = left[i];
		k++;
		i++;
		trocas++;
	}

	// Copy remaining element of right, if any
	while (j < len2){
		arr[k] = right[j];
		k++;
		j++;
		trocas++; 
	}

	get<0>(loginfo)+=trocas;
    get<1>(loginfo)+=comparacoes;
}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(array_t arr, int n, loginfo_t& loginfo) {
	
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSortTim(arr, i, min((i+RUN-1),(n-1)), loginfo);

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n; size = 2*size){
		
		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n; left += 2*size){
			
			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),(n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if(mid < right)
				mergeTim(arr, left, mid, right, loginfo);
		}
	}
}
