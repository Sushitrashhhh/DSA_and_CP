#include <iostream>
#include <vector>

using namespace std;
int search(vector<int> &A, int B){
    int start =0, end = A.size() - 1;

    while(start <=end){
        int mid = start+(end-start)/2;
        if (A[mid]== B){
            return mid;
        }
        if (A[start] <= A[mid]){ //left sorted arr
            if (A[start] <= B && B < A[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if (A[mid] <=B && B<=A[end]){
                start=mid+1;

            }
            else{
                end=mid-1;
            }
        }
    }
    return -1; // Element not found
}