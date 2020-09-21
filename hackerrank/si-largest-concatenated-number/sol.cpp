#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>

using namespace std;

int myCustomCompare(string a, string b){
    string ab = a.append(b);
    string ba = b.append(a);
    if(ab > ba) return 1;
    return 0;
}

void solve(vector<string>& v){
    sort(v.begin(), v.end(), myCustomCompare);

    for(auto c : v){
        cout<<c;
    }
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        vector<string> myvec;
        for(int i = 0 ; i < n; i++){
            cin>>arr[i];
            myvec.push_back(to_string(arr[i]));
        }

        solve(myvec);
    }
    
    return 0;
}