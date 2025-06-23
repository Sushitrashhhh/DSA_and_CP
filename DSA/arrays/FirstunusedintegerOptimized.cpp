#include <iostream>
#include <vector>
using namespace std;

void  swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int firstMissingPositive(vector<int> &A){
    for(int i = 0; i < A.size(); i++) {
        // While the current element is in the range and not in its correct position
        while (A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i]) {
            swap(A, i, A[i] - 1);
        }
    }
    for (int i =0; i<A.size(); i++){
        if (A[i] != i + 1) {
            return i + 1; // Return the first missing positive integer
        }
    }
    return A.size() + 1;
}

/*

Ye function kis problem ka solution hai?

"Find the first missing positive integer" (from an unsorted array) — Leetcode ka classic question.

Pehla loop:

Har element ko uske "correct index" par place karne ki koshish kar raha hai.
For example, 1 ko index 0, 2 ko index 1, and so on.

Yeh tabhi karega jab:

A[i] is positive

A[i] <= size of array

A[i] != A[A[i] - 1] → means wo already correct jagah pe nahi hai.

Swap karta rahega until ya toh wo element correct jagah pe chala jaye ya condition break ho jaye.

Second loop:

Ab har index i pe check kar raha hai kya A[i] == i + 1 hai.

Agar nahi, matlab wohi pe pehla missing positive mil gaya → return i + 1.

Agar sab correct jagah pe ho, then return A.size() + 1.

For example, input = [1, 2, 3] → return 4.
*/