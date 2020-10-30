#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int solve1(int arr[], int n) {
    // optimization based on solve()
    // incl -> max non adjacent subsequence sum till i including i
    // excl -> max non-adjacent subsequence sum till i excluding i
    int incl = arr[0];
    int excl = 0;
    for(int i = 1; i < n; i++){
        int temp = incl;
        incl = max(max(arr[i], excl + arr[i]), incl);
        excl = temp;
    }
    return incl;
}

int solve(int arr[], int n){
    // dp state = max non-adjacent subsequence sum till i including i
    // TC - O(N^2)
    // SC - O(N)
    int dp[n];
    dp[0] = arr[0];
    dp[1] = arr[1];

    for(int i = 2; i < n; i++){
        int maxVal = INT_MIN;
        for(int j = 0; j <= i-2; j++){
            maxVal = max(maxVal, dp[j]);
        }
        dp[i] = maxVal + arr[i];
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];

        cout<<solve1(arr, n)<<"\n";
    }
    
    return 0;
}