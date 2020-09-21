#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
long long solve1(int arr[], int n, int a, int b, long long prefixSum[]){
    // optimized
    // Idea - Prefix Sum, Compute the cumulative sum before hand.
    // TC - O(N+Q)
    // SC - O(N)
    if(a == 0){
        return prefixSum[b];
    }
    else if(a == b){
        return arr[a];
    }
    return prefixSum[b]-prefixSum[a-1];
}

long long solve(int arr[], int n, int a, int b){
    // Bruteforce
    // TC - O(N*Q)
    // SC - O(1)
    long long ans = 0;
    for(int i = a; i <= b; i++){
        ans += arr[i];
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n;
    cin>>n;
    int arr[n];
    long long prefixSum[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    prefixSum[0] = arr[0];

    for(int i = 1 ; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
        // cout<<prefixSum[i]<<" ";
    }
    // cout<<"\n";
    int q;
    cin>>q;
    while (q--)
    {
        int a, b;
        cin>>a>>b;
        // cout<<solve(arr, n, a, b)<<"\n";
        cout<<solve1(arr, n, a, b, prefixSum)<<"\n";
    }
    

    return 0;
}