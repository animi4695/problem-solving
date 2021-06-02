#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>

using namespace std;
vector<string> split(string s, string delim);
vector<string> getUserIds(vector<string> logs, int threshold);

vector<string> getUserIds(vector<string> logs, int threshold){
    map<string, int> mp;
    for(auto logLine : logs) {
        vector<string> log = split(logLine, " ");
        mp[log[0]]++;
        if(log[0] != log[1])
            mp[log[1]]++;
    }

    vector<string> ans;
    for(auto m : mp){
        if(m.second >= threshold){
            ans.push_back(m.first);
        }
    }

    sort(ans.begin(), ans.end(), [](auto a,auto b){
        return stoi(a) < stoi(b);
    });

    return ans;
}

vector<string> split(string s, string delim){
    vector<string> res;
    int i = 0;
    int n = s.length();
    string word = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            res.push_back(word);
            word = "";
        }
        else{
            word += s[i];
        }
    }

    if(word.length() > 0)
        res.push_back(word);
    return res;
}

int main() {
    vector<string> input = { "345366 89921 45",
                "029323 38239 23", 
                "38239 345366 15", 
                "029323 38239 77",
                "345366 38239 23",
                "029323 345366 13",
                "38239 38239 23"};

    vector<string> ans = getUserIds(input, 2);
    for(auto a : ans){
        cout<<a<<" ";
    }
}