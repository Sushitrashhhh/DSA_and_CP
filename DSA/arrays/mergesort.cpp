//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// MERGE FUNCTION: Merges two sorted halves of the array
void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> left;
    vector<int> right;

    // Fill left part from index start to mid - 1
    for (int i = start; i < mid; i++) {
        left.push_back(arr[i]);
    }

    // Fill right part from mid to end - 1
    for (int j = mid; j < end; j++) {
        right.push_back(arr[j]);
    }

    // Pointers for merging
    int i = 0, j = 0;
    int mainptr = start;  // this points to the actual array index

    // Merge left and right arrays in sorted order
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[mainptr++] = left[i++];
        } else {
            arr[mainptr++] = right[j++];
        }
    }

    // If anything left in left array
    while (i < left.size()) {
        arr[mainptr++] = left[i++];
    }

    // If anything left in right array
    while (j < right.size()) {
        arr[mainptr++] = right[j++];
    }
}

// MERGESORT FUNCTION: Divides and sorts
void mergeSort(vector<int> &arr, int start, int end) {
    // base case: 0 or 1 element
    if (start >= end - 1) return;

    int mid = start + (end - start) / 2;

    // Recursively sort left and right halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid, end);

    // Merge sorted halves
    merge(arr, start, mid, end);
}

// MAIN FUNCTION
int main() {
    vector<int> arr = {1, 4, 5, 10, 2, 3, 6, 12};

    int start = 0;
    int end = arr.size();

    // Call mergesort
    mergeSort(arr, start, end);

    // Print sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

Merge Function:

Left aur Right vectors banaye to split the array

Pehle half ko left[] me daala, dusre ko right[] me

mainptr original array ko point karta hai

Jab tak left aur right me dono me elements hai, compare karo aur chhota wala daal do

Baad me jo bach gaye unko copy karo


MergeSort Function:

Divide karte jao jab tak 1-1 element na bach jaye (start >= end-1)

Fir merge call hota hai recursively


Main Function:

Array diya {1, 4, 5, 10, 2, 3, 6, 12}

Sorted output: 1 2 3 4 5 6 10 12

*/