#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int MOD = 1e9+7;

int dp0[100001] = {0};
int dp1[100001] = {0};

void precompute(){
    dp0[1] = dp1[1] = 1;
    for(int i = 2; i < 100001; i++){
        dp0[i] = (dp0[i-1]%MOD + dp1[i-1]%MOD)%MOD;
        dp1[i] = dp0[i-1]%MOD;
    }
}

void solve(int n){
    int p0 = 1;
    int p1 = 1;
    int c0, c1;
    for(int i = 2; i <= n; i++){
        c0 = (p0%MOD + p1%MOD)%MOD;
        c1 = p0;
        p0 = c0;
        p1 = c1;
    }
    cout<<(c0+c1)%MOD<<"\n";
}

int main(){
    int t;
    cin>>t;
    precompute();
    while (t--)
    {
        int n;
        cin>>n;
        int res = (dp0[n]%MOD + dp1[n]%MOD)%MOD;
        cout<<res<<"\n";
    }
    
    return 0;
}