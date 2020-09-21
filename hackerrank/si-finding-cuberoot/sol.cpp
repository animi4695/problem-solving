#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
long long pow(long long a, long long n){
    long long x = a;
    long long ans = 1;
    while(n){
        if(n&1){
            ans = ans*x;
        }
        x = x*x;
        n = n>>1;
    }
    return ans;
}

long long cuberoot(long long n){
    int sign = n < 0 ? -1 : 1;
    if(sign == -1){
        n = -n;
    }
    // ideally hi should be n.. but according to constraints, n can never cross 1e18
    // Therefore, we can select hi as something that never exceeds 1e18 when cubed...
    int lo = 1, hi = 1e6;
    while(lo <= hi){
        long long mid = lo + (hi-lo)/2;
        long long val = pow(mid,3);
        if(val == n){
            if(sign == -1){
                return -mid;
            }
            return mid;
        }
        if(val < n){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    return -1;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<cuberoot(n)<<"\n";
    }
    
    return 0;
}