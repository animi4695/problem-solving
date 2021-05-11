#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;
bool solve(string s1, string s2){
    unordered_set<char> ust1;
    unordered_set<char> ust2;
    for(auto ch : s1){
        ust1.insert(ch);
    }

    for(auto ch : s2){
        if(ust1.find(ch) != ust1.end()){
            return true;
        }
    }

    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        solve(s1,s2) == true ? cout<<"Yes" : cout<<"No";
        cout<<"\n";
    }
    
    return 0;
}