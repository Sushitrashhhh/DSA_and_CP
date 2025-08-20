// using recursion and backtracking to print all subsets of a set

#include<iostream>
#include<vector>
using namespace std;

void PS(vector<int> &arr, vector<int> &ans, int i) {
    if(i == arr.size()) {
        for(int val: ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    // Include the current element
    ans.push_back(arr[i]);
    PS(arr, ans, i + 1);
    // Exclude the current element
    ans.pop_back(); //backtrack
    PS(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans; // To store the current subset
    PS(arr, ans, 0); // Start recursion from index 0
    return 0;
}