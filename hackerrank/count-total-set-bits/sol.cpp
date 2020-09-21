#include<iostream>
#include <limits>
#include<vector>

using namespace std;

int optimalCountSetBits(int n);
int main(){
    int A = 3;
    // unsigned long long count = 0;
    // // int ans[A+1];
    // vector<int> ans(A+1, 0);
    // for(int i = 1; i <=A; i++){
    //     ans[i] = ans[i&(i-1)]+1;
    // }
    
    // for(auto a : ans){
    //     count+=a;
    // }
    // cout<<count;
    // return count%1000000007;
    return optimalCountSetBits(A);
}

int optimalCountSetBits(int n){
    // TC - O(LogN)
    n++; // ignore the 0, since all the bits are unset

    int powerOf2 = 2;
    int count = n/2;

    while(powerOf2 <= n){

        int totalPairs = n/powerOf2;

        count += (totalPairs>>1)*powerOf2;

        // if totalpairs was odd, then add the left out set bits.

        count += (totalPairs&1) ? (n%powerOf2) : 0;

        powerOf2 = powerOf2 << 1;
    }

    cout<<count;

    return count%1000000007;
}