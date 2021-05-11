#include<iostream>
#include<climits>
#include<cmath>
#include<unordered_map>

using namespace std;
bool solve(unordered_map<int, int>& umap, int w, int wr){
    long long sum = wr;
    for(auto& wi : umap){
        if(sum >= w){
            return true;
        }
        while(wi.second >= 2){
            sum += (2*wi.first);
            wi.second -= 2;
        }
    }
    if(sum >= w) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, w, wr;
        cin>>n>>w>>wr;
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            umap[x]++;
        }
        bool isSuccess = solve(umap, w, wr);
        if(isSuccess) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}