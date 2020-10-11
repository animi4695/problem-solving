#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool isPerfectSquare(long long num){
    // long long lo = 0, hi = num;
    // long long ans;
    // while (lo <= hi) {
    //     long long mid = (lo+hi)/2;
    //     long long val = mid*mid;
    //     if(val == num) return true;
    //     if(val < num) {
    //         lo = mid+1;
    //         ans = mid;
    //     }
    //     else hi = mid-1;
    // }
    // return false;

    long double sr = sqrt(num);
    return ((sr- floor(sr)) == 0);
}
int solve(long long a, long long b){
    int res = 0;
    for(int i = a; i <= b; i++){
        if(isPerfectSquare(i) == true){
            res++;
        }
    }
    return  res;
}

int optimized(long long a, long long b){
    return floor(sqrt(b)) - ceil(sqrt(a))+1;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long a, b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
    
    return 0;
}