#include<iostream>
#include <limits>

using namespace std;
bool checkbit(int n, int i){
    return (n>>i)&1;
}
bool subset(int arr[], int n, int k){
    // TC - O(N*2^N)
    // SC - O(N*2^N)

    for(int i = 0; i < 1<<n; i++){
        int sum = 0;

        for(int j = 0 ; j <31; j++){
            if(checkbit(i,j)) sum += arr[j];
        }

        if(sum == k) return true;
    }
    return false;
}

// recursive
bool subsetsum(int arr[], int n, int k, int currSum, int idx){
    // TC - O(2^N)
    // SC - O(2^N)

    // base condition
    if(n == idx) return currSum==k;
    // backtracking.
    // 2 options - take the sum into consideration and don't take into consideration
    return subsetsum(arr, n, k, currSum + arr[idx], idx+1) || subsetsum(arr, n, k, currSum, idx+1);
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        
        // iterative
        // bool isFound = subset(arr, n , k);
        
        // recursive
        bool isFound = subsetsum(arr, n , k, 0, 0);

        if(isFound) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}