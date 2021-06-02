#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

bool myCmp(string &a, string &b){
    int p1 = a.find(' ');
    int p2 = b.find(' ');
    string s1 = a.substr(p1+1);
    string s2 = b.substr(p2+1);
    if(s1 == s2)
        return a < b;
    return s1 < s2;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       vector<string> letters, digits, res;
       for(auto log : logs) {
           int pos = log.find(' ');
           if(isdigit(log[pos+1])){
               digits.push_back(log);
           }
           else{
               letters.push_back(log);
           }
       }

       sort(letters.begin(), letters.end(), myCmp);
       res.insert(res.end(), letters.begin(), letters.end());
       res.insert(res.end(), digits.begin(), digits.end());
       return res;
    }
};

int main() {
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    Solution s = Solution();
    vector<string> res = s.reorderLogFiles(logs);
    for(auto c : res){
        cout<<c<<"\n";
    }
}