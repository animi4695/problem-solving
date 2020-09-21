#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
void solve(string &str){
    int cnt[26] { 0 };
    for(int i = 0; i < str.length(); i++){
        cnt[str[i]-'a']++;
    }

    for(int i = 0; i < str.length(); i++){
        if(cnt[str[i]-'a'] > 1){
            cout<<str[i];
            return;
        }
    }
    cout<<".";
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string str;
        cin>>str;
        solve(str);
        cout<<"\n";
    }
    
    return 0;
}