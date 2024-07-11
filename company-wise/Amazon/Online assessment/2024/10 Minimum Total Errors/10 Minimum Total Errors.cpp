#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

int findNumZeroes(string s);
int findNumOnes(string s);
int solve(string errorString, int x, int y);
string modifyString(string s, char replaceChar);

// ref - https://www.reddit.com/r/leetcode/comments/19b2h09/really_hard_problem_in_amazon_oa/

int main(){
    string errorString = "101!1";
    int x = 2, y = 3;
    // Expected output = 9
    // modify the string to 2 string by replacing ! with 0 and 1 - Assuming there will be only one '!'  
    string errorString1 = errorString;
    replace(errorString1.begin(), errorString1.end(), '!', '0');
    
    string errorString2 = errorString;
    replace(errorString2.begin(), errorString2.end(), '!', '1');
    int ans = min(solve(errorString1, x, y), solve(errorString2, x, y));
    cout<<ans<<" ";

    return 0;
}

string modifyString(string s, char replaceChar){
    string res = "";
    for(auto ch : s){
        if(ch == '!')
            res.push_back(replaceChar);
        else
            res.push_back(ch);
    }

    return res;
}

int solve(string errorString, int x, int y){
    int x_count = 0, y_count = 0;
    for(int i = 0; i < errorString.size(); i++) {
        if(errorString[i] == '1'){
            y_count+= findNumZeroes(errorString.substr(i+1));
        }
        else if(errorString[i] == '0'){
            x_count+= findNumOnes(errorString.substr(i+1));
        }
    }

    int ans = x_count * x + y_count * y;
    return ans;

}

int findNumZeroes(string s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0')
            count++;
    }
    return count;
}

int findNumOnes(string s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            count++;
    }
    return count;
}
