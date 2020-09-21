#include<iostream>
#include<climits>

using namespace std;
bool checkBit(int n, int i){
    return (n>>i)&1;
}
int pow(int x, int n, int d){
    if(n == 0) return 1%d;
    long long ans = 1, base = x;
    while(n > 0){
        if(n%2 == 1){
            ans = (ans*base)%d;
        }
        base = (base*base)%d;
        n = n>>1;
    }

    if(ans < 0){
        ans = (ans+d)%d;
    }

    return ans%d;
}

int main(){
    int x = -1, n=1, d = 20;
    cout<<pow(x,n,d);
    return 0;
}