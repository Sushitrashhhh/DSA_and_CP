

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubArr(vector<int> &arr){
    map<int, int> list;

    vector<int> prefixSum(arr.size());
    prefixSum.push_back(arr[0]);

    list[prefixSum[0]] = 0;
    int lSubArr = 0;
    for(int i=1;i<arr.size();i++){
        int tempKey = 0;
        prefixSum[i] = prefixSum[i-1]+arr[i];
        
        if(list.find(prefixSum[i])!=list.end())
        {
            tempKey = i-list[prefixSum[i]]; 
            
        }
        else if(prefixSum[i] == 0)
        { 
            tempKey = i;
            
        }
        
        else
        
        list[prefixSum[i]] = i;
        
        
       if(tempKey>lSubArr)
       lSubArr =tempKey;
    }
    return lSubArr;
}

int main() {
    vector<int> arr = {1, -1, 3, 2, -2, 4, -4};
    int result = longestSubArr(arr);
    cout << "Length of the largest subarray with sum zero: " << result << endl;
    return 0;
}
// This code finds the length of the largest subarray with a sum of zero.
// It uses a map to store the prefix sums and their indices.

/*
  Humne ek function banaya `longestSubArray` jisme humne vector<int> ko 
  reference se pass kiya (using &arr).

  Fir ek map liya `list` jisme do int values hain — yeh store karega 
  prefixSum aur uska pehla index.

  Ek vector `prefixSum` banaya, jo original array ke size ka hai.
  Usme pehle element (0th index) pr `arr[0]` daala.

  Uske baad, map `list` me pehla prefix sum aur uska index store kiya 
  (prefixSum[0] = arr[0] → index 0).

  Fir loop chala i = 1 se leke array ke end tak.
  Har iteration me ek temporary variable `tempKey` liya jo 0 se start hota hai.

  Loop me:
  - prefixSum[i] = prefixSum[i-1] + arr[i];  // cumulative sum update

  Fir 3 conditions check ki:
  1. Agar yeh prefix sum pehle map me mila ho toh
     → iska matlab beech ka subarray ka sum 0 hai
     → tempKey = i - list[prefixSum[i]]

  2. Agar prefixSum[i] == 0 ho toh
     → matlab 0 se i tak ka subarray ka sum 0 hai
     → tempKey = i

  3. Agar prefixSum pehli baar mila ho
     → toh usko map me daal diya

  Last me agar tempKey > lSubArr ho gaya
  → toh lSubArr ko update kar diya

  Function return karega lSubArr — i.e. longest subarray with sum 0

  Main function me ek vector define kiya, function ko call kiya 
  aur uska result print kar diya.

  `return 0;` lagaya kyunki yeh `int main()` function ka requirement hota hai.
*/
