#include<iostream>
#include<vector>
#include <limits>

using namespace std;

bool solve(string str, int n){
    vector<int> arr(26, -1);
    arr[str[0]-'A'] = 0;
    for(int i = 1; i < str.length(); i++){
        if(arr[str[i]-'A'] == -1){
            arr[str[i]-'A'] = i;
        }
        else if(arr[str[i]-'A'] != i-1){
            return false;
        }
        else
            arr[str[i]-'A'] = i;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        // cin.ignore();
        string str;
        cin>>str;
        bool isSus = solve(str, n);
        if(isSus){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}