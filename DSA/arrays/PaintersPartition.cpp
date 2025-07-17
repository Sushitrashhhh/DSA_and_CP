/*
Problem intuition:
You’ve got boards of different lengths.

You’ve got m painters.

A painter can only paint continuous boards.

You wanna assign boards to painters such that time taken by the slowest painter is minimum.

*/

#include <iostream>
#include <vector>   
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime){
    int painter = 1, time =0;

    for(int i = 0; i<n; i++){
        if (time + arr[i]  <= maxAllowedTime){
            time +=arr[i];
        }
        else{
            painter++;
            time = arr[i]; // new painter starts with current board
        }
    }
    return painter <=m;
}

int minTimeToPaint(vector<int> &arr, int n, int m){
    int sum = 0, maxVal = INT_MIN;

    for (int i =0; i<n; i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);       
    }

    int st = maxVal;
    int end = sum;
    int ans = -1;

    while(st <=end){
        int mid = st+(end-st)/2;
        if(isPossible(arr, n, m, mid)){
            int ans = mid;
            end = mid-1;//left side search
        }
        else{
            st = mid + 1; //right side search
        }
        return ans;

    }
}


int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int m = 2; // number of painters

    int result = minTimeToPaint(arr, n, m);
    cout << "Minimum time to paint all boards: " << result << endl;

    return 0;
}

/*
Bhai binary search ka range board ke sizes ke upar chal raha hai. 
Har mid value pe check kar rahe hain ki kitne painters lagenge agar har kisi ko mid max time diya jaye.
Jo pehla mid possible hota hai, wahi minimum required time hai. Smart greedy + binary combo 
*/