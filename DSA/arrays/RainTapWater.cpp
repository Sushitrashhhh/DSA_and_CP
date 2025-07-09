#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(const vector<int> &A){
    vector<int> li;
    vector<int> ri;

    int lmax = 0;
    for(int i = 0; i < A.size(); i++){
        li.push_back(lmax);
        lmax = max(lmax, A[i]);
    }

    int rmax = 0;
    for(int j = A.size() - 1; j >= 0; j--){
        ri.push_back(rmax);
        rmax = max(rmax, A[j]);
    }
    reverse(ri.begin(), ri.end());

    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        int water = min(li[i], ri[i]) - A[i];
        if(water > 0) ans += water;
    }
    return ans;
}

/*
Har block ke left me sabse bada block kya tha (li)

Har block ke right me sabse bada block kya tha (ri)

Agar left aur right dono bada hai current se, toh uske upar paani rukega = min(lmax, rmax) - height[i]

Agar ye -ve aaya, iska matlab paani nahi ruk sakta
*/