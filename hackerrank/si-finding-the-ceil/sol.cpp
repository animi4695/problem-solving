#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int findceil(int arr[], int n, int key){
    int lo = 0, hi = n-1;
    int ans = INT_MAX;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(arr[mid] < key){
            lo = mid+1;
        }
        else{
            // this can be potential ans. so store it and look for better.
            ans = arr[mid];
            hi = mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    // sort and do binary search for q queries.
    sort(arr, arr+n);

    int q;
    cin>>q;
    while(q--){
        int key;
        cin>>key;
        int res = findceil(arr, n, key);
        cout<<res<<"\n";
    }
    
    return 0;
}