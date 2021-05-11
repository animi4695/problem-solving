#include<iostream>
#include<climits>
#include<cmath>
#include<vector>

using namespace std;
int mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long arr;
        cin>>arr;
        // important line
        sum  = (sum + arr + mod)%mod;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        sum = (2*sum)%mod;
        cout<<sum<<"\n";
    }
    return 0;
}