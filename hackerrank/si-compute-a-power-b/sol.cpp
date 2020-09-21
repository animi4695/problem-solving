#include<iostream>
#include <limits>

using namespace std;
int mod = 1e9+7;
long long compute(int a, int n){

    if(n == 0) return 1;
    int x = compute(a, n/2)%mod;
    if(n%2==0){
        return (x*x)%mod;
    }
    return (x*x*a)%mod;
}

bool checkbit(int N, int i){
    // cout<<N<<"-";
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
    int t;
    cin>>t;
    while (t--)
    {
        int a,n;
        cin>>a>>n;
        // long long val = (compute(a,n))%mod;
        long long  val = (pwr(a,n))%mod;

        cout<<val<<"\n";
    }
    
    return 0;
}