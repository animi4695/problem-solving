#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
#include<unordered_map>
#include<queue>

using namespace std;

string getMinCost(string s);

struct CustomComparator {
    vector<int>& count;

    CustomComparator(vector<int>& count) : count(count) {}

    bool operator()(const char& a, const char& b) const {
        return count[a - 'a'] != count[b - 'a'] ?
            count[a - 'a'] > count[b - 'a'] :
            a > b;
    }
};

string getMinCost(string s){
    vector<int> count(26, 0);
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '?'){
            count[s[i] - 'a']++;
        }
    }

    CustomComparator comparator(count);
    priority_queue<char, vector<char>, CustomComparator> q(comparator);
    for(char c = 'a'; c <= 'z'; c++){
        q.push(c);
    }

    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '?'){
            if(q.empty()){
                return "-1";
            }
            res += q.top();
            count[q.top() - 'a']++;
            q.pop();
        } else {
            res += s[i];
        }
    }
    return res;
}

int main() {
    string res;
    res = getMinCost("abcdefghijklmnopqrstuvwxyz??");
    cout<<res;
    return 0;
}