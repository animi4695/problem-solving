#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

int getLongestMatch(string text, string regex);

int main(){
    string text = "hackerrank";
    string regex = "ack*r";

    int res = getLongestMatch(text, regex);
    cout<<res<<" ";

    return 0;
}

int getLongestMatch(string text, string regex) {
    int res = -1;
    size_t startPos = regex.find("*");
    string prefix = regex.substr(0, startPos);
    string suffix = regex.substr(startPos + 1);

    for(int i = 0; i <= text.size() - suffix.size(); i++) {
        if(text.substr(i, suffix.size()) == suffix) {
            // found suffix
            for(int j = 0; j <= i; j++){
                if(text.substr(j, prefix.size()) == prefix){
                    // found prefix
                    int currLen = i + suffix.size() - j;
                    res = max(res, currLen);
                }
            }
        }
    }
    return res;
}