#include <iostream>
#include <vector>
using namespace std;

int BS(vector<int> arr, int tar, int st, int end) {
    if (st > end) return -1; // Base case: element not found
    int mid = st + (end - st) / 2; // Avoid overflow

    if (arr[mid] == tar) return mid; // Element found
    else if (arr[mid] < tar) return BS(arr, tar, mid + 1, end); // Search in right half
    else return BS(arr, tar, st, mid - 1); // Search in left half
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = BS(arr, target, 0, arr.size() - 1);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}