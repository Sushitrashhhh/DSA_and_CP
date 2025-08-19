#include <iostream>
using namespace std;
void printNum(int n){
    // cout<<n<< "";
    if (n==1) {
        cout<<1<<endl;
        return;
    }
   cout<<n<< " "; 
    printNum(n-1);
    
}

int factorial(int n){
    if (n==0) return 1;
    return n*factorial(n-1); 
}

int sum(int n){
    if (n==1) return 1;
    return n + sum(n-1);
}

int main() {
    printNum(5);
    cout<< factorial(5)<<" ";
    cout<<sum(4)<<" ";
    return 0;
}