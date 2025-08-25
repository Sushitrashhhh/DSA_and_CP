#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void getAns(vector<int>& arr, int i, int target, vector<vector<int>>& ans, vector<int>& combin) {
        if (target == 0) { 
            ans.push_back(combin);
            return;
        }
        if (i >= arr.size() || target < 0) return;

        // include arr[i]
        combin.push_back(arr[i]);
        getAns(arr, i, target - arr[i], ans, combin); // stay at i (unlimited use)
        combin.pop_back();

        // exclude arr[i]
        getAns(arr, i + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAns(arr, 0, target, ans, combin);
        return ans;
    }
};
