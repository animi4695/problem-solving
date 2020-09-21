#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int hcf(int a, int b){
    // Euclidean algorithm
    if(a==0) return b;

    return hcf(b%a, a);
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int val = 1;
        if(a > b){
            val = hcf(b,a);
        }
        else{
            val = hcf(a,b);
        }
        long long mul = (long long)a*(long long)b;
        long long lcm = (mul)/(long long)val;
        cout<<lcm<<" "<<val<<"\n";
    }
    
    return 0;
}