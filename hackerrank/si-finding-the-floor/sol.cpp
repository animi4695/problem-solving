#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>

using namespace std;
int findFloor(int arr[], int n, int key){
    int lo = 0;
    int hi = n-1;
    int ans = INT32_MIN;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(arr[mid] > key){
            hi = mid-1;
        }
        else{
            ans = arr[mid];
            lo = mid+1;
        }
    }
    return ans;
}
int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++) cin>>arr[i];
    int q;
    cin>>q;
    
    // logic - sort and do BS to find the q queries
    sort(arr, arr+n);
    while (q--)
    {
        int key;
        cin>>key;
        int res = findFloor(arr,n, key);
        cout<<res<<"\n";
    }
    
    return 0;
}