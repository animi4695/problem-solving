#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
int solve(int arr[], int n){
    // generate all subarrays and get the sum.
    int ans = INT_MIN; 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            if(sum == 0){
                ans = max(ans, j-i+1);
            }
        }
    }
    return ans == INT_MIN ? 0 : ans;
}

int solve2(int arr[], int n){
    // generate all subarrays and get the sum.
    // carry forward the sum to remove extra k for loop
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == 0){
                ans = max(ans, j-i+1);
            }
        }
    }
    return ans;
}

int solve3(int arr[], int n){
    // unordered_map to avoid calculating sum multiple times
    unordered_map<int, int> prefixSum;  //{sum , index};
    int maxLen = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(arr[i] == 0 && maxLen == 0) maxLen = 1;
        if(sum == 0){
            maxLen = i+1;
        }

        if(prefixSum.find(sum) != prefixSum.end()){
            maxLen = max(maxLen, i - prefixSum[sum]);
        }
        else{
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<solve2(arr, n)<<"\n";
    }
    
    return 0;
}