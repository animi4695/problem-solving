#include<iostream>
#include <limits>
#include<unordered_map>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        unordered_map<int, int> umap;
        for(int i = 0 ; i < n; i++){
            cin>>arr[i];
            umap[arr[i]]++;
        }
        int val = 0;
        for(auto ump : umap){
            if(ump.second == 1)
            {
                val = ump.first;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(val == arr[i]){
                cout<<i+1<<"\n";
                break;
            }
        }
    }
    
    return 0;
}