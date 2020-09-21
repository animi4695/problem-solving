#include<iostream>
#include <limits>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
int mycomp(pair<int,int> x, pair<int,int> y){
    if(x.second == y.second){
        return x.first < y.first;
    }
    return x.second < y.second;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];

        map<int,int> mp;
        for(int i = 0 ; i < n; i++) {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto c : mp){
            v.push_back(c);
        }

        sort(v.begin(), v.end(), mycomp);

        for (auto a : v) {
            while(a.second){
                cout << a.first << " ";
                a.second--;
            }
        }

        // countSort(arr, n);

        cout<<"\n";
    }
    
    return 0;
}