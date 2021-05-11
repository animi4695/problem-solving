#include<iostream>
#include <limits>
#include<vector>
#include<unordered_map>

using namespace std;
int solve(vector<int>& arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n ,arr[j] > arr[i]; j++){
            if((j-i) == (arr[j]-arr[i])){
                ans++;
            }
        }
    }
    return ans;
}

long long countPairs(vector<int>& arr, int n)
{
    unordered_map<long long, long long> map;
    for (int i = 0; i < n; i++)
        map[arr[i] - i]++;
  
    long long res = 0;
    for (auto x : map) {
        long long cnt = x.second;
        res += ((cnt * (cnt - 1)) / 2);
    }
  
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        cout<<countPairs(arr, n)<<"\n";
    }
    
    return 0;
}