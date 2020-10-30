#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
#define MOD 1000000007

int dp[1000001] = {0};

long long solve(int n){
    // dp state = num of ways to fill floor of size 5*i
    // Top Down
    if(n < 0){
        return 0;
    }
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    if(dp[n]>0){
        return dp[n];
    }

    long long val = (solve(n-1)+solve(n-2)+(8*solve(n-5)));
    dp[n] = val%MOD;

    return dp[n];
}

void precompute(int n){
    // dp state = num of ways to fill floor of size 5*i
    // bottom up
    // if(n < 0){
    //     return 0;
    // }
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i = 3; i <= n; i++){
        long long val = 0;
        if(i >= 5){
            val += (8*dp[i-5]);
        }
        val = val + dp[i-1]+ dp[i-2];
        dp[i] = val%MOD;
    }
    // return dp[n];
}

int main(){
    // https://stackoverflow.com/questions/45055249/algorithm-to-count-the-number-of-ways-a-floor-of-size-5n-can-be-filled-with-ti
    int t;
    cin>>t;
    precompute(1000000);
    while (t--)
    {
        int n;
        cin>>n;
        // cout<<solve(n)<<"\n";
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}