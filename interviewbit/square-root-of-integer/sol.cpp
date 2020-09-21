#include<iostream>
#include<climits>

using namespace std;
int sqrt(int A){
    int lo = 0, hi = A;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        long long val = (long long)mid*(long long)mid;
        if(val == (long long )A){
            return mid;
        }

        if(val < (long long)A){
            lo = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }
    return ans;
}
int main(){

    int A = 1e9;
    cout<<sqrt(A);
    return 0;
}