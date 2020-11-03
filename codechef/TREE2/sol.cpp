#include<iostream>
#include<unordered_set>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        unordered_set<int> uset;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] != 0) uset.insert(arr[i]);
        }
        cout<<uset.size()<<"\n";
    }
    
    return 0;
}