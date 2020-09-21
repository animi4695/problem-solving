#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
int BS(vector<int>  &arr, int n, int key){
    int lo = 0, hi = n-1;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(arr[mid] == key){
            return arr[mid];
        }
        else if(arr[mid] > key){
            lo = mid+1;
        }
        else{
            hi = mid-1;
            ans = mid;
        }
    }
    return arr[ans];
}

void solve(vector<int> &arr, int n, int arrB[], int m){
    // pre processing
    int rank = 0;
    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++){
        auto itr = mp.find(arr[i]);
        if(itr == mp.end()){
            rank = rank+1;
            mp.insert({arr[i], rank});
        }
    }
    vector<int> result(m);
    for(int i = 0; i < m; i++){
        if(arrB[i] >= arr[0] || (arrB[i] <=  arr[0] && arrB[i] >= arr[n-1])){
            // apply BS for the correct fit
            // int idx = lower_bound(arr.begin(), arr.end(), myCustomCompare)-arr.begin();
            int idx = BS(arr, n, arrB[i]);
            result[i] = mp[idx];
        }
        else{
            result[i] = rank+1;
        }
    }

    for(auto r : result){
        cout<<r<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];

        int m;
        cin>>m;
        int arrB[m];
        for(int i = 0; i < m; i++) cin>>arrB[i];

        solve(arr, n, arrB, m);
        cout<<"\n";
    }
    
    return 0;
}