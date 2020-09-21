#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
void solve(int arr[], int n, int k){
    map<int,int> mp;
    int dist_count = 0;
    for(int i = 0; i < k; i++){
        if(mp[arr[i]] == 0) dist_count++;
        mp[arr[i]]++;
    }
    cout<<dist_count<<" ";
    for(int i = k ; i< n; i++){
        if(mp[arr[i-k]] == 1) dist_count--;
        mp[arr[i-k]]--;

        if(mp[arr[i]] == 0) dist_count++;
        mp[arr[i]]++;

        cout<<dist_count<<" ";
    }

}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
       int n, k;
       cin>>n>>k;
       int arr[n];
       for(int i = 0;i < n; i++) cin>>arr[i];

       solve(arr, n, k);
       cout<<"\n";
    }
    
    return 0;
}