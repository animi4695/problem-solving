#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int solve1(string s, int n){
    // using const space (optimized DP)
    int prev1;
    int prev2;
    prev1 = prev2 = 1;
    for(int i = 2; i <= n; i++){
        int curr = 0;

        if(s[i-1] >= '0'){
            curr = prev1;
        }

        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '6')){
            curr = (curr + prev2)%MOD;
        }

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int solve(string s, int n){
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 0;

        if(s[i-1] >= '0'){
            dp[i] = dp[i-1];
        }

        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '6')){
            dp[i] = (dp[i] + dp[i-2])%MOD;
        }
    }

    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s, n)<<"\n";
    }
    
    return 0;
}