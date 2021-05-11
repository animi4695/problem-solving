#include<iostream>
#include <limits>

using namespace std;
void solve() {
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(s.length()%2 == 0 && (a&1 || b&1)){
        cout<<"-1\n";
        return;
    }

    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == '?' && s[n-1-i] != '?'){
            s[i] = s[n-1-i];
        }
        else if(s[i] != '?' && s[n-1-i] == '?'){
            s[n-1-i] = s[i];
        }
        a -= (s[i] == '0');
        b -= (s[i] == '1');
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '?'){
            if(a > b){
                s[i] = s[n-1-i] = '0';
                a--;
            }
            else{
                s[i] = s[n-1-i] = '1';
                b--;
            }
            if(i != n/2 || (i == n/2 && n%2 == 0)){
                if(s[i] == '1') b--;
                else a--;
            }
        }
    }

    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]){
            cout<<"-1\n";
            return;
        }
    }

    if(a == 0 && b == 0){
        cout<<s<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}