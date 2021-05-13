#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool solve(long long n, long long x, long long k){
    long long i = 0;
    while(i < n){
        if(i == x)
            return true;
        i = i+k;
    }
    i = n-1;
    while(i >= 0){
        if(i == x) return true;
        i = i-k;
    }
    return false;
}

bool solve2(long long n, long long x, long long k) {
    if(x%k == 0)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long n,x,k;
        cin>>n>>x>>k;
        n = n+2;
        if(solve(n,x,k))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}