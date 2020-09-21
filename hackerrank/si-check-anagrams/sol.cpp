#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
bool solve(string &a, string &b){
    int cnt[26] = {0};

    if(a.length() != b.length()) return false;

    for(int i = 0; i < a.length(); i++){
        cnt[a[i]-'a']++;
    }

    for(int i = 0; i < b.length(); i++){
        if(cnt[b[i]-'a'] <= 0 ) return false;
        cnt[b[i]-'a']--; 
    }

    return true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a,b;
        cin>>a>>b;

        if(solve(a,b)) cout<<"True\n";
        else cout<<"False\n";
    }
    
    return 0;
}