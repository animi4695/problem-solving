#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int solve(int W[], int S[], int k, int n){
    // Integer 0/1 knapsack - DP(Tabulation- bottonUP)
    // dp state - max value to fill knapsack of size j using 1st i items [1...i]
    int dp[n+1][k+1];
    // Base condition
    // For all the cells of 0th row (i-1,j) is not available
    for(int j = 0; j <= k; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++) {
            if(j >= W[i-1]){
                dp[i][j] = max((dp[i-1][j-W[i-1]] + S[i-1]), dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}

int solve1(int W[], int S[], int j, int i, vector<vector<int>> &dp){
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(j < W[i]) {
        dp[i][j] = solve1(W,S,j, i-1, dp);
        return dp[i][j];
    }
    else{
        dp[i][j] = max(solve1(W,S, j-W[i], i-1, dp) + S[i], solve1(W,S,j, i-1, dp));
        return dp[i][j];
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int s, n;
        cin>>s>>n;
        int W[n], S[n];
        for(int i = 0; i < n; i++)
            cin>>W[i]>>S[i];
        
        // cout<<solve(W, S, s, n)<<"\n";

        vector<vector<int>> dp(n+1, vector<int>(s+1, -1));

        cout<<solve1(W,S,s,n-1,dp)<<"\n";
    }
    return 0;
}