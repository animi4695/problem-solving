#include<iostream>
#include<limits>
#include<vector>
#include<algorithm>

using namespace std;
bool BSR(int arr[], int k, int lo, int hi){
    if(lo>hi) return false;

    int mid = (lo+hi)/2;
    if(arr[mid] == k) return true;
    else if(arr[mid] < k) return BSR(arr,k, mid+1, hi);
    return BSR(arr,k,lo,mid-1);
}

bool solveTriplet(int arr[], int n, int k){
    sort(arr, arr+n);

    // binary search a+b+c = k
    // search b = k-a-c;
    for(int i = 0 ; i < n-2 ; i++){
        int a = arr[i];
        int bc = k-a;
        for(int j = i+1; j<n-1; j++){
            int c = arr[j];
            int b = bc-c;
            if (BSR(arr, b, j + 1, n - 1)) {
                return true;
            }
        }
    }
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

        if(solveTriplet(arr, n, k)){
            cout<<"true\n";
        }
        else
        {
            cout<<"false\n";
        }
        
    }
    
    return 0;
}