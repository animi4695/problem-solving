#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int dp[100001] = {0};
int MOD = 1e9+7;
void precompute();

void solve(int n) {
    // Dynamic Programming
    // DP state -> Num of ways to get Sum = i;
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        int temp = 0;
        for(int j = 1; j <= 6 && (i-j) >= 0; j++) {
            temp = (temp%MOD + dp[i-j]%MOD)%MOD;
        }
        dp[i] = temp%MOD;
    }
    cout<<dp[n]<<"\n";
}

void precompute(){
    dp[0] = 1;
    for(int i = 1; i <= 100001; i++){
        int temp = 0;
        for(int j = 1; j <= 6 && (i-j)>=0; j++){
            temp = (temp%MOD + dp[i-j]%MOD)%MOD;
        }
        dp[i] = temp%MOD;
    }
}

int main(){
    int t;
    cin>>t;
    precompute();
    while (t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}