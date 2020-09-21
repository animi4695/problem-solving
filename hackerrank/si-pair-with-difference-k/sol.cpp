#include<iostream>
#include <limits>
#include<algorithm>

using namespace std;
bool BSR(int arr[], int k, int lo, int hi){
    if(lo > hi) return false;

    int mid = (lo+hi)/2;
    if(arr[mid] == k) return true;
    else if(arr[mid] < k) return BSR(arr, k, mid+1, hi);
    return BSR(arr, k, lo, mid-1);
}

bool solve(int arr[], int n, int k){
    sort(arr, arr+n);
    // binary search for the ans a-b = k
    // b = k + a;
    for(int i = 0 ; i < n ; i++){
        int a = arr[i];
        int b = k+a;
        if(BSR(arr, b, i+1, n-1)){
            return true;
        }
    }
    // --------------------- or -----------------
    // 2 ptr techinque to find a-b = k
    // int p1 = 0, p2 = n-1;

    // while (p1 < p2)
    // {
    //     long long val = (arr[p2] - arr[p1]);
    //     if(abs(val) == abs(k)) return true;
    //     else if(val < k) p2--;
    //     else p1++;
    // }
    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0 ; i < n; i++) cin>>arr[i];

        if(solve(arr, n, k))
            cout<<"true\n";
        else
            cout<<"false\n";
    }
    
    return 0;
}