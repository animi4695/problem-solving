#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
long long pwr(int a, int n);
bool checkbit(int N, int i);
long long solve(int n);

int mod = 1e9+7;
long long solve(int n) {
    // 0<=x<=(pwr(2,n)-1)
    // if we manually calculate the solution upto 3, we can observe there is a pattern for ans. 
    // i.e ans = pwr(2, n-1). Only prob is we have to apply modulo properly
    return pwr(2, n-1);
}

bool checkbit(int N, int i){
    return (N>>i)&1;
}

long long pwr(int a, int n){
    // iterative binary representation
    long long ans = 1, x = a;
    for (int i = 0; i < 31; i++)
    {
        if(checkbit(n, i) == true){
            ans = (ans*x)%mod;
        }
        x = (x*x)%mod;
    }

    return ans%mod;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}