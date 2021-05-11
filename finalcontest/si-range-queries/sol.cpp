#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int lowerbound(int arr[], int n, int a);
int upperbound(int arr[], int n, int b);

int lowerbound(int arr[], int n, int a){
    int lo = 0, hi = n-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] >= a){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return lo;
}

int upperbound(int arr[], int n, int b){
    int lo = 0, hi = n-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] <= b){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return hi;
}

int solve(int arr[], int n, int k, int a, int b){
    int ans = 0;
    ans = upperbound(arr, n, b) - lowerbound(arr, n, a) + 1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        sort(arr, arr+n);
        int q;
        cin>>q;
        while(q--){
            int a, b;
            cin>>a>>b;
            cout<<solve(arr, n, k, a, b)<<"\n";
        }
    }
    
    return 0;
}