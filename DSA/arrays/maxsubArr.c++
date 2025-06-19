// Kadane’s Algorithm — used to find the maximum sum subarray in a 1D array.

// vector<int> = You're passing a vector of integers to the function.
// &A = This means you're passing the vector by reference, allowing the function to modify it if needed.
//const → You are not allowed to modify the vector inside the function.
#include <iostream>
#include <vector>
using namespace std;
int maxSubArr(const vector<int> &A){
    int maxsum=0, carrysum=0;
    for(int i=0; i<A.size(); i++){
        carrysum+=A[i];
        if (carrysum < 0) {
            carrysum = 0; // Reset carrysum if it goes negative
        }
    
        if (carrysum > maxsum) {
            maxsum = carrysum; // Update maxsum if carrysum is greater
        }
    }
    return maxsum;
}

/*
"Ek maxSubArr function banaya jisme vector<int>& A as reference pass kiya. 
maxSum aur carrySum ko 0 se initialize kiya. 
Phir loop lagaya i = 0 se A.size() tak. 
Har step pe A[i] ko carrySum me add kiya. 
Agar carrySum < 0 ho gaya toh usse 0 kar diya. 
Agar carrySum > maxSum hua toh maxSum ko update kar diya. 
Last me maxSum return kar diya."
*/