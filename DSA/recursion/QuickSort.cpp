#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int idx=st-1, pivot=arr[end];

    for(int j=st;j<end;j++){
        if(arr[j]<pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quicksort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivot = partition(arr, st, end);

        quicksort(arr, st, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
}

// int partition(vector<int>& arr, int st, int end) {
//     int pivot = arr[end];
//     int i = st - 1;

//     for (int j = st; j < end; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[end]);
//     return i + 1;
// }

int main() {
    vector<int> arr={10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size()-1);

    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}