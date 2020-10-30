#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;
int dp[2001][2001];

void precompute(int n, int r){
    for(int j = 1; j <= r; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    }
}

int solve1(int n, int r){
    // In solve(), dp[i][j] is only dependent on dp[i-1][j-1] and dp[i-1][j]. 
    // i.e to fill ith row, we only need (i-1)th row
    int dp[2][r+1];
    for(int j = 1; j <= r; j++) dp[0][j] = 0;
    for(int i = 0; i <= 1; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            dp[i%2][j] = (dp[(i-1)%2][j-1] + dp[(i-1)%2][j])%MOD;
        }
    }
    return dp[n][r];

}

int solve(int n, int r){
    // dp state dp(i,j) -> Number of ways to choose j items from i items.
    // ncr = (n-1)c(r-1) + (n-1)cr
    // TC = O(N*R)
    // SC O(N*R)
    long long dp[n+1][r+1];
    // base condition
    for(int j = 1; j <= r; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    }
    return dp[n][r];
}

int main(){
    
    // fast-io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    precompute(2000,2000);
    while (t--)
    {
        int n,r;
        cin>>n>>r;
        if(n == r || r == 0) cout<<"1"<<"\n";
        else if(r == 1) 
            cout<<n%MOD<<"\n";
        else if(n < r) 
            cout<<"0\n";
        else
            cout<<dp[n][r]<<"\n";
    }
    
    return 0;
}