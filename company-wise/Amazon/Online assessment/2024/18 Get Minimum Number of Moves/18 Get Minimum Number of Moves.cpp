#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int countDistinctPasswords(string password) {
    int ans = 0;
    int n = password.length();
    int total_substrings = n*(n-1)/2 + 1;
    int duplicates = 0;

    unordered_map<char, int> freq;
    for(auto c : password){
        freq[c]++;
    }

    for(auto pair : freq){
        duplicates += pair.second *(pair.second - 1)/2;
    }

    ans = total_substrings - duplicates;
    return ans;
}

int main() {
    string password = "abaa";
    int res = countDistinctPasswords(password);

    cout<<res;

    return 0;
}