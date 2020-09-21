#include<iostream>
#include <limits>

using namespace std;
long long mod = 1e9+7;
long long factorials[1000001];
long long  fact(int n){
    factorials[0] = factorials[1] = 1;
    for(int i = 2; i <=n ;i++){
        factorials[i] = (i*factorials[i-1])%mod;
    }

    return factorials[n]%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        // cin>>n;
        long long  val = fact(n)%mod;

        printf("%lld\n", val%mod);
    }
    
    return 0;
}