#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

bool containsRepeatingChars(string s){
    vector<int> cnt(26, 0);
    for(auto ch : s){
        if(cnt[ch-'a'] > 0)
            return true;
        cnt[ch-'a']++;
    }
    return false;
}

vector<string> KSubstring(string s, int k){
    unordered_set<string> uset;

    for(int i = 0; i < s.size()-k+1; i++){
        if(containsRepeatingChars(s.substr(i, k)) == false)
            uset.insert(s.substr(i, k));
    }

    vector<string> res(uset.begin(), uset.end());

    return res;
}

int main(){
    vector<string> res = KSubstring("awaglknagawunagwkwagl", 4);
    for(auto r : res){
        cout<<r<<"\n";
    }
}
